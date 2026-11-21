// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortLevelDuplicatableInterface.h"
#include "FMInWorldCableOptionsComponent.generated.h"

class UFMDeviceCablePortComponent;

UCLASS(ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFMInWorldCableOptionsComponent : public UActorComponent, public ILevelDuplicatable
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnAnyOptionChanged();

	UFUNCTION()
	void OnCableConnected(UFMDeviceCablePortComponent* SourcePort, UFMDeviceCablePortComponent* ConnectedPort);

	UFUNCTION()
	void OnCableDisconncted(UFMDeviceCablePortComponent* SourcePort, UFMDeviceCablePortComponent* DisconnectedPort);

	UFUNCTION()
	void OnOptionsLoaded();

};

