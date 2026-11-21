// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialStyleDataAsset.generated.h"

class UChatColorSchemeDataAsset;
class USocialActionButtonStyleDataAsset;
class USocialChatChromeColorSchemeDataAsset;
class USocialChatChromeMarginsDataAsset;
class USocialChatChromeStyleDataAsset;
class USocialChatMarkupStyleDataAsset;
class USocialChatStyleDataAsset;
class USocialCheckBoxStyleDataAsset;
class USocialFontStyleDataAsset;
class USocialListMarginsDataAsset;
class USocialListStyleDataAsset;
class USocialProfanityDataAsset;
class USocialRadioBoxStyleDataAsset;
class USocialScrollBarStyleDataAsset;
class USocialSoundSchemaDataAsset;

UCLASS(BlueprintType)
class USocialStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialFontStyleDataAsset> SmallFontStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialFontStyleDataAsset> NormalFontStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialFontStyleDataAsset> LargeFontStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialFontStyleDataAsset> ChatFontStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialListStyleDataAsset> SocialListStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialListMarginsDataAsset> SocialListMargins;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialChatStyleDataAsset> ChatStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialChatChromeStyleDataAsset> ChatChromeStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialChatChromeMarginsDataAsset> ChatChromeMargins;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialChatChromeColorSchemeDataAsset> ChatChromeColorScheme;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<UChatColorSchemeDataAsset> ChatColorScheme;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialSoundSchemaDataAsset> SoundSchema;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialActionButtonStyleDataAsset> ActionButtonStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialCheckBoxStyleDataAsset> CheckBoxStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialRadioBoxStyleDataAsset> RadioBoxStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialScrollBarStyleDataAsset> ScrollBoxStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialChatMarkupStyleDataAsset> MarkupStyle;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialProfanityDataAsset> ProfanityDataAsset;

};

