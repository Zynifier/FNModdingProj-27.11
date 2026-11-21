// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "FortGameFeatureAction_AddAttributesToPlayer.generated.h"

class UAttributeSet;

USTRUCT()
struct FFortGameFeatureAction_PlayerAttributesToAdd
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_PlayerAttributesToAdd", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_PlayerAttributesToAdd")
	FFortAttributeInitializationKey AttributeInitKey;

};

UCLASS(MinimalAPI, meta=(DisplayName="Add Attribute Set To Player"))
class UFortGameFeatureAction_AddAttributesToPlayer : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Attribute Sets")
	TArray<FFortGameFeatureAction_PlayerAttributesToAdd> Attributes;

};

