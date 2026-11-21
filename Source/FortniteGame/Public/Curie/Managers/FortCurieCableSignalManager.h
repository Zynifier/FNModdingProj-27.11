// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Curie/FortCurieManagerComponent.h"
#include "CurieManagerComponent.h"
#include "FortCurieCableSignalManager.generated.h"

class UFortCurieCableSignalManagerConfig;

USTRUCT()
struct FFortCurieCableSignalManagerTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FFortCurieCableSignalManagerTickFunction> : public TStructOpsTypeTraitsBase2<FFortCurieCableSignalManagerTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

UCLASS()
class UFortCurieCableSignalManager : public UFortCurieManagerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FFortCurieCableSignalManagerTickFunction PrimaryManagerTick;

	UPROPERTY(Transient)
	TObjectPtr<UFortCurieCableSignalManagerConfig> InternalManagerConfig;

};

UCLASS()
class UFortCurieCableSignalManagerConfig : public UCurieManagerComponentConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCurieCableSignalManagerConfig", meta=(Patchable))
	int32 SignalsProcessedPerTick;

};

