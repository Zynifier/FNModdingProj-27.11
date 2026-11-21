// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChatChromeColorScheme.h"
#include "SocialChatChromeColorSchemeDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialChatChromeColorSchemeDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FChatChromeColorScheme Style;

};

