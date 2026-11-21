// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPlaylistCuratedContent.generated.h"

USTRUCT(BlueprintType)
struct FFortPlaylistCuratedContent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlaylistCuratedContent")
	TArray<FString> CuratedLinkCodes;

};

