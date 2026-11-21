// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChatMarkupStyle.h"
#include "SocialChatMarkupStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialChatMarkupStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FChatMarkupStyle Style;

};

