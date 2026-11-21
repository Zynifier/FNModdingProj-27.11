// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChatStyle.h"
#include "SocialChatStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialChatStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FChatStyle Style;

};

