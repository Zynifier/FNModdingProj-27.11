// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_StormSicknessControl.generated.h"

class AActor;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStromSicknessOptionsUpdated);

USTRUCT(BlueprintType)
struct FStormSicknessOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Storm Sickness")
	bool bIsEnabled;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Storm Sickness")
	bool bResetWarnAndSicknessAllowedOnDeath;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Storm Sickness")
	TObjectPtr<AActor> ModSource;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_StormSicknessControl : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DequeueStormSickenessOptions(AActor* ModSource, bool bShouldUpdate = true);

	UFUNCTION(BlueprintCallable)
	void EnqueueStormSickenessOptions(FStormSicknessOptions StormOptions);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Storm Sickness")
	TArray<FStormSicknessOptions> OptionsQueue;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Storm Sickness")
	FScalableFloat IsEnabled;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Storm Sickness")
	FScalableFloat IsResetWarnAndSicknessAllowedOnDeath;

	UPROPERTY(BlueprintAssignable, Category="Storm Sickness")
	FOnStromSicknessOptionsUpdated OnStormSicknessOptionsUpdated;

};

