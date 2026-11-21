// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaAIRuntimeParametersComponent.generated.h"

class IFortAthenaAIRuntimeParametersProvider;
class UFortAthenaAIRuntimeParameters;
class UObject;

UCLASS(Abstract, Transient)
class UFortAthenaAIRuntimeParameters : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ExtractedLevel;

};

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParametersComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<TSubclassOf<UFortAthenaAIRuntimeParameters>, TScriptInterface<IFortAthenaAIRuntimeParametersProvider>> RegisteredParametersProviders;

	UPROPERTY(Transient)
	TMap<TSubclassOf<UObject>, TObjectPtr<UFortAthenaAIRuntimeParameters>> ExtractedRuntimeParameters;

};

UINTERFACE(MinimalAPI)
class UFortAthenaAIRuntimeParametersProvider : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEAI_API IFortAthenaAIRuntimeParametersProvider
{
	GENERATED_BODY()

};

