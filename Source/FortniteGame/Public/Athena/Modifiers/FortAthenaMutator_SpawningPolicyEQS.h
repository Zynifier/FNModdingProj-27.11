// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "Athena/Modifiers/FortAthenaMutator_EQSProviderInterface.h"
#include "Athena/Modifiers/FortAthenaMutator_SpawningPolicyBase.h"
#include "FortAthenaMutator_SpawningPolicyEQS.generated.h"

class UEnvQuery;

UCLASS(Abstract, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpawningPolicyEQS : public AFortAthenaMutator_SpawningPolicyBase, public IFortAthenaMutator_EQSProviderInterface, public INavAgentInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Base Query", meta=(AllowPrivateAccess="true", EditCondition="bWaitForNavmeshToBeLoaded"))
	float BaseQueryingAttemptIntervalTimeSeconds;

	UPROPERTY(EditDefaultsOnly, Category="Base Query", meta=(AllowPrivateAccess="true"))
	TSoftObjectPtr<UEnvQuery> BasePlacementQuery;

};

