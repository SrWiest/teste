<h1 align="center">Hi there, I'm <a href="https://www.pspx.ru/forum/" target="_blank">in1975</a> 
<img src="https://github.com/blackcater/blackcater/raw/main/images/Hi.gif" height="32"/></h1>
<h3 align="center">This is the repository for Hen 3.2.4 rus mod</h3>
<h3 align="center">This HEN is a branch (modification) <a href="https://github.com/PS3Xploit/PS3HEN" target="_blank">of this</a></h3>
<p align="center">
  <img alig src="https://github-profile-trophy.vercel.app/?username=nikolaevich23&column=6&rank=SSS,SS,S,AAA,AA,A,B,C" />
</p>

## Изменения в 3.2.4 
- Новый способ установки HEN (для исключения проблем с разделом сеть). Если после загрузки HEN.P3T эксплоит не сработал - закройте браузер, откройте вновь, наберите адрес и пропустите загрузку файла 2й раз (нет необходимости качать его еще раз).
- Теперь опции не перезаписываются при обновлении на новую версию. При установке первый раз опции устанавливаются в положение включено или выключено.
- Переведены уведомления для опций (в самом хен пока на английском).
- Заменен шрифт для отображения спецсимволов в меню.
- Добавлен фикс утечки памяти в RetroArch
- Добавлен экран блокировки при входе в псн, если не очищены системные вызовы
- Добавлены пункты отключения syscall и включения их после отключения, проверки состояния и другие пункты в сервисные инструменты.
- Добавлен пункт перегрузки только LV2
- Добавлен пункты включения/выключения FTP (отдельный модуль, вебман не требуется)
- Добавлен раздел PSN для создания фейк-активации (метод аналогичный с cfw)
- Добавлена куча пунктов в раздел инструментов информации и сохранения (время работы, скорость вентиляторов, температура и другое)
- Добавлена куча пунктов в раздел сервисные инструменты
- Добавлена возможность поменять кнопки Х и О местами в инструментах xRegistry
- Добавлена функция монтирования папки dev_hdd0\packages для установки всех pkg из одной папки Стандарт.
- Добавлен пункт установки/удаления плагина для отображения дополнительной информации в играх/хмб (фпс, температура и другое). Для настройки плагина нажмите L1+L3. ВНИМАНИЕ - в webman есть аналогичный плагин, так что установка этого плагина может вызвать конфликты (да и нет нужды, поскольку в вебман почти тоже самое).
- Добавлен пункт для управления трофеями (удаление всего набора трофеев, разблокировка/блокировка трофеев). **ВНИМАНИЕ разблокированные трофеи в PSN не синхронизируются.**
- Добавлен файл для разблокировки c00 игр в \dev_hdd0\packages\C00_EDAT_UNLOCKS.pkg
- Добавлены иконки для профиля 
- Добавлены файлы *.m3u в \dev_hdd0\VIDEO\ для просмотра тв/видео через movian 
- Другие мелкие изменения

'ВНИМАНИЕ - некоторые процессы занимают время, дожидайтесь окончания их обработки, иначе при включении другого процесса консоль может зависнуть.'

## Изменения в 3.2.3
- Добавлено опция включения горячих клавиш (L2 и R2). 
- Для большей совместимости горячие клавиши по умолчанию выключены. 

## Изменения в 3.2.2
- Добавлена очистка логов, которые отправляются при соединении в PSN с целью уменьшения риска бана.
- Добавлено отображение того, чиститься ли кеш браузера, история, аутентификация. Добавлена опция включения/отключения логов очистки.
- Включена обработка клавиш:
    - R2 отключает dev_hdd\boot*.txt из загрузки (бывает необходимо при конфликте с плагинами)
    - L2 отключает все плагины в том числе и плагины hen, поэтому информацию о включении хен видно не будет, иконка не сменится, но ядро загрузится, в чем можно убедиться запустив игру/софт, либо обновив XMB (например через вход в дистанционное управление и выход - тогда иконка изменится)

## Изменения в 3.2.1
- Удалено обработка горячих клавиш (для большей совместимости с некоторыми моделями)

## Изменения в 3.2.0
### Плагин:
- Добавлено: Автоматическая перезагрузка после успешной первоначальной установки HEN из сети и USB (метод 2.2)
- Добавлено: доступ в черный список к доморощенным NP0APOLLO / NP00PKGI3, когда системные вызовы CFW отключены
- Добавлено: поддержка Libcrypt для игр PS1 (файлы LSF/SBI).
- Добавлено: PSX Bios исправлен с кодом продукта 0x85 для игр PAL.
- Добавлено: опции переключения на очистку веб-браузера при активации HEN. (Аутентификация, кэш, файлы cookie, история)

### Полезная нагрузка:
- Добавлено: обнаружение горячих клавиш:
    - удерживайте R2, чтобы отключить boot_plugins.txt (бывает полезно, когда плагины вешают пс3)
- Добавлено: улучшен статус open_path.
- Улучшено: Map_path.
- Улучшено: PS3MAPI.

## Изменения в 3.1.7
- Добавлены функции Mamba 8.4 (Изменен ps3mapi_process_page_allocate, чтобы использовать page_table в качестве процесса ввода и вывода, а также сопоставление page_address ядра, которое было выделено. Добавлен ps3mapi_process_page_free, который принимает page_table (сопоставление page_address процесса/ядра) и освобождает его.
- Заменен rco для возможности обновления с hdd в пункте обновление системы. Для отображения включать нужно где настройки сети (после комбинации будет ниже). Комбинация клавиш: L1+L2+R1+R2+L3+dpad_down должно появится меню, там пункт system update debug. обновления нужно размещать в dev_hdd0\updater\01\ (вы можете назвать файл обновления как угодно). Достаточно включить 1 раз и потом после активации HEN дополнительные пункты будут доступны.
- Убрал предупреждение об эпилепсии (пусто)

## Изменения в 3.1.6
- Перекомпилировал с целью устранения проблем с папочными играми (если проблемы остаются, смените бекап менеджер)
- Мелкие правки в меню

## Изменения в 3.1.5
- Добавлено отображение различных магазинов через обслуживание (по умолчанию отключено)
- :exclamation: **ВНИМАНИЕ**:exclamation: Совместимость магазинов с HEN RUS не гарантируется! Магазины могут поломать меню, добавить свой метод инициализации, так что будьте аккуратнее :exclamation:
- аудио патч по умолчанию теперь выключен
- добавлена функция удаления HEN через обслуживание
- мелкие правки

## Изменения в 3.1.4
- Добавлено отображение сейвов ps2 в утилах
- обновлена информация о системе (3.1.4)

## Изменения в 3.1.3
- Изменены иконки HEN ON / HEN OFF для более четкого понимания включен хен или нет (Иконки изготовила @Виктория)
- Изменен метод восстановления бекапа act.bak
- Добавлена очистка (удаляются webbrowser/history.xml, http/auth_cache.dat, http/cookie.dat);
- расширение RAP теперь может быть как rap, так и RAP
- исправлено отображение 1080p (ранее было описание как 2160)
- мелкие правки

## Изменения в 3.1.2
### Добавлены опции в раздел обслуживания:
- Теперь можно включить/отключить автообновление через интернет и с флешки (dev_usb00?/HEN_UPD.pkg) (если опция выключена - хен срабатывает чуть быстрее)
- Теперь можно включить/отключить патч libaudio для наушников, поскольку с наушниками Sony конфликты - выбирайте нужно ли это вам или нет
- Теперь можно включить/скрыть пункт "включить hen" (работает после обновления xmb - если включен, будет виден пункт и надпись "хен уже активирован", если выключен, пункт будет скрыт)
- Теперь можно включить/скрыть утилиты
- Теперь можно включить/скрыть пункт "Управление файлами PKG"

### Другое:
- Заменен сервер проверки обновлений
- Иконки к указанным опциям переключаются
- Теперь можно сделать обновление с помощью файла HEN_UPD.pkg не только с правого порта (dev_usb000), но и с левого (dev_usb001)
- Добавлен перевод для новых опций
- xai_plugin доработан.
- Обновлена информация о PS3HEN
- Другие мелкие правки
