// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIEvaluator.h"
#include "Athena/FortGameStateAthenaEnums.h"
#include "FortAthenaAIEvaluator_DormantUntilPhase.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIEvaluator_DormantUntilPhase : public UFortAthenaAIEvaluator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Behaviour", meta=(AllowPrivateAccess="true"))
	FScalableFloat bIsEnabled;

	UPROPERTY(EditAnywhere, Category="Behaviour", meta=(AllowPrivateAccess="true"))
	bool bDisabledInCreative;

	UPROPERTY(EditAnywhere, Category="Behaviour", meta=(AllowPrivateAccess="true"))
	EAthenaGamePhaseStep RequiredGamePhaseStep;

	UPROPERTY(EditAnywhere, Category="Behaviour", meta=(AllowPrivateAccess="true"))
	FScalableFloat DelayAfterPhase;

	UPROPERTY(EditAnywhere, Category="Behaviour", meta=(AllowPrivateAccess="true"))
	FScalableFloat RandomDeviationAfterPhase;

};

