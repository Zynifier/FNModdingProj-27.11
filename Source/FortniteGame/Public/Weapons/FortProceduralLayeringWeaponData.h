// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortProceduralLayeringWeaponData.generated.h"

class UFortItemChooserData;
class UProxyTable;

USTRUCT(BlueprintType)
struct FFortProceduralLayeringWeaponData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortProceduralLayeringWeaponData")
	TObjectPtr<UProxyTable> ProxyTable;

	UPROPERTY(EditAnywhere, Category="FortProceduralLayeringWeaponData")
	bool bUseMotionMatchingWithoutProxyTable;

	UPROPERTY(EditAnywhere, Category="FortProceduralLayeringWeaponData")
	TSubclassOf<UFortItemChooserData> ItemChooserDataClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortItemChooserData> ItemChooserData;

};

