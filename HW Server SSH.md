# 登入 
ssh AN4114011@140.116.246.48 -p 2024

# 密碼 
KKkuan4114011

# 上傳檔案 
scp -P 2024 hw7-1.c AN4114011@140.116.246.48:/home/AN4114011/HW9

# 連結編譯 
gcc main.c pA.c -o pA

# 看測資 
cd /; cd share; cd HW7_TC