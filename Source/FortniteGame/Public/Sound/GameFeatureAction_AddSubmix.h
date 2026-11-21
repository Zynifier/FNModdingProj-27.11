// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction_AudioActionBaseFortnite.h"
#include "GameFeatureAction_AddSubmix.generated.h"

class USoundSubmix;

USTRUCT()
struct FGameFeatureSubmixEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio")
	TSoftObjectPtr<USoundSubmix> Submix;

	UPROPERTY(EditAnywhere, Category="Audio")
	TSoftObjectPtr<USoundSubmix> Parent;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Submixes"))
class UGameFeatureAction_AddSubmix : public UGameFeatureAction_AudioActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Audio", meta=(TitleProperty="{Submix} with parent {Parent}"))
	TArray<FGameFeatureSubmixEntry> SubmixList;

};

