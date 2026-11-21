// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChatChromeStyle.h"
#include "SocialChatChromeStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialChatChromeStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FChatChromeStyle Style;

};

