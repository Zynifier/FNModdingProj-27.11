// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraDataInterface.h"
#include "FortCurieFireNiagaraDataInterface.generated.h"

UCLASS(meta=(Category="Curie"))
class UFortCurieFireNiagaraDataInterface : public UNiagaraDataInterface
{
	GENERATED_BODY()

};

UINTERFACE(MinimalAPI)
class UFortCurieFireParticleDataInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortCurieFireParticleDataInterface
{
	GENERATED_BODY()

};

