set CURRENT_PATH=%~dp0
echo %CURRENT_PATH%

protoc --proto_path=%CURRENT_PATH% --cpp_out=%CURRENT_PATH% %CURRENT_PATH%Lobby.proto