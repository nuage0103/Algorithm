-- 코드를 작성해주세요
WITH T AS(
    SELECT 
    (
        CASE
        WHEN AVG(SCORE) >= 96 THEN 'S'
        WHEN AVG(SCORE) >= 90 THEN 'A'
        WHEN AVG(SCORE) >= 80 THEN 'B'
        ELSE 'C'
        END
    ) AS GRADE, 
    (
        CASE
        WHEN AVG(SCORE) >= 96 THEN 0.2
        WHEN AVG(SCORE) >= 90 THEN 0.15
        WHEN AVG(SCORE) >= 80 THEN 0.1
        ELSE 0
        END
    ) AS BONUS, EMP_NO
    FROM HR_GRADE
    GROUP BY EMP_NO
)

SELECT E.EMP_NO, E.EMP_NAME, T.GRADE, (E.SAL * T.BONUS) AS BONUS
FROM HR_EMPLOYEES AS E
JOIN T ON T.EMP_NO = E.EMP_NO
ORDER BY 1
;