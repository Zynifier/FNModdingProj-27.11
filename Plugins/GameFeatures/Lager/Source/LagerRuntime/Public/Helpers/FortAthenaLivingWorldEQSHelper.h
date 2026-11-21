// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/NavAgentInterface.h"
#include "AI/Navigation/NavigationTypes.h"
#include "GameFramework/Actor.h"
#include "FortAthenaLivingWorldEQSHelper.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFortAthenaLivingWorldEQSHelper : public AActor, public INavAgentInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldEQSHelper")
	FNavAgentProperties NavAgentProperties;

};

