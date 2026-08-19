-- 코드를 작성해주세요
WITH T AS(
    SELECT EMP_NO, 
        (
            CASE
            WHEN AVG(SCORE) >= 96 THEN 'S'
            WHEN AVG(SCORE) >= 90 THEN 'A'
            WHEN AVG(SCORE) >= 80 THEN 'B'
            ELSE 'C'
            END
        ) AS GRADE
    FROM HR_GRADE
    GROUP BY EMP_NO
)

SELECT E.EMP_NO, E.EMP_NAME, T.GRADE, ROUND((
    CASE (T.GRADE)
    WHEN 'S' THEN 0.2
    WHEN 'A' THEN 0.15
    WHEN 'B' THEN 0.1
    ELSE 0
    END
) * E.SAL) AS BONUS
FROM HR_EMPLOYEES AS E
JOIN T ON E.EMP_NO = T.EMP_NO
ORDER BY EMP_NO
;