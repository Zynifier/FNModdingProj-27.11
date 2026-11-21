// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Tasks/TargetingFilterTask_BasicFilterTemplate.h"
#include "Types/TargetingSystemTypes.h"
#include "TargetingFilterTask_ObstructedByWorld.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UTargetingFilterTask_ObstructedByWorld : public UTargetingFilterTask_BasicFilterTemplate
{
	GENERATED_BODY()

public:
	UTargetingFilterTask_ObstructedByWorld(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Target Obstructed Filter")
	FVector GetSourceLocation(const FTargetingRequestHandle& TargetingHandle) const;

	UFUNCTION(BlueprintNativeEvent, Category="Target Obstructed Filter")
	FVector GetSourceOffset(const FTargetingRequestHandle& TargetingHandle) const;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	FGameplayTagQuery TargetFilterQuery;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	FVector DefaultSourceOffset;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bComplexTrace : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeAllAttachedToTarget : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeAthenaVehicleOfTarget : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeInstigator : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeAllAttachedToInstigator : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeAthenaVehicleOfInstigator : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeAllAttachedToSource : 1;

	UPROPERTY(EditAnywhere, Category="Targeting Filter | Options")
	uint8 bExcludeAthenaVehicleOfSource : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Targeting Filter | Options")
	uint8 bExcludeAthenaVehicleFromObstructionChecks : 1;

};

