// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortAsyncObjectManager.generated.h"

class IFortAsyncObjectInterface;

UCLASS(MinimalAPI)
class AFortAsyncObjectManager : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TScriptInterface<IFortAsyncObjectInterface>> AsyncObjects;

};

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortAsyncObjectInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortAsyncObjectInterface
{
	GENERATED_BODY()

};

