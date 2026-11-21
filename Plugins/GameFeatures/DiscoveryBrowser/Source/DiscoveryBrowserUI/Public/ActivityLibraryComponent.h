// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActivityLibraryComponent.generated.h"

class UFortActivitySelector;

UCLASS()
class UActivityLibraryComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortActivitySelector> ActivitySelector;

};

