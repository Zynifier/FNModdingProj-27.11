// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChatChromeMargins.h"
#include "SocialChatChromeMarginsDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialChatChromeMarginsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FChatChromeMargins Style;

};

