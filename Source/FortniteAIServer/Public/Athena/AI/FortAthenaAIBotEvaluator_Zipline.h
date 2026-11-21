// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Movement.h"
#include "FortAthenaAIBotEvaluator_Zipline.generated.h"

class AFortPlayerPawn;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_Zipline : public UFortAthenaAIBotEvaluator_Movement
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnZiplineStateChanged(bool bIsZiplining, AFortPlayerPawn* FortPlayerPawn);

	UPROPERTY(EditAnywhere, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName CurrentDestinationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FName ZiplineTargetKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName LastZiplineUsedName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FName ZiplineMoveExecutionStatusKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FName ZiplineEntryLocationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FName ZiplineExitLocationKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FName ZiplineLastUsageTimeName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FName ZiplineUsageExecutionStatusName;

	UPROPERTY(EditAnywhere, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat WaitTimeBetweenZiplineRandomChoices;

	UPROPERTY(EditDefaultsOnly, Category="Zipline", meta=(AllowPrivateAccess="true"))
	FScalableFloat ProbabilityToUseZipline;

};

