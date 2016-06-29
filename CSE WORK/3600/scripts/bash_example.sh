 printf '%s ' 'Which fruit do you like most?'
read -${BASH_VERSION+e}r fruit

case $fruit in
    apple)
        echo 'Mmmmh... I like those!'
        ;;
    banana)
        echo 'Hm, a bit awry, no?'
        ;;
    orange|tangerine)
        echo $'Eeeks! I don\'t like those!\nGo away!'
        exit 1
        ;;
    *)
        echo "Unknown fruit - sure it isn't toxic?"
esac
