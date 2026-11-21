// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaZipline.h"
#include "FortAthenaSplineZipline.generated.h"

class USplineComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAthenaSplineZipline : public AFortAthenaZipline
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEGAME_API void CheckZiplineDisableHotfix();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortAthenaSplineZipline", meta=(EditInline="true"))
	TObjectPtr<USplineComponent> ZiplineSpline;

	UPROPERTY(EditDefaultsOnly, Category="Zipline")
	FScalableFloat AttachLinesToPolesHotfix;

};

