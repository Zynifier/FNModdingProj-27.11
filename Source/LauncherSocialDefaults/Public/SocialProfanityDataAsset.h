// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialProfanityData.h"
#include "SocialProfanityDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialProfanityDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	TArray<FProfanityData> ProfanityData;

};

