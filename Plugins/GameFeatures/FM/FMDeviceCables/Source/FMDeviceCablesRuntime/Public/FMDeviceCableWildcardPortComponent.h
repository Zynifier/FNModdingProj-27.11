// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FMDeviceCablePortComponent.h"
#include "FMDeviceCableWildcardPortComponent.generated.h"

class UFMDeviceCablePortComponent;
class UFMDeviceCableWildcardPortComponent;
enum class EDeviceCablePortDataType : uint8;

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), ClassGroup=("Harmonix"))
class FMDEVICECABLESRUNTIME_API UFMDeviceCableWildcardPortComponent : public UFMDeviceCablePortComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWildcardDataTypeChanged, UFMDeviceCableWildcardPortComponent*, WildcardPort, EDeviceCablePortDataType, DataType);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWildcardPortSlotSetFromSave, UFMDeviceCableWildcardPortComponent*, WildcardPort, bool, bHasConnections);

public:
	UPROPERTY(BlueprintAssignable)
	FOnWildcardDataTypeChanged OnWildcardDataTypeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnWildcardPortSlotSetFromSave OnWildcardPortSlotSetFromSave;

	UPROPERTY(EditAnywhere, Category="FMDeviceCableWildcardPortComponent")
	int32 SlotIndex;

	UPROPERTY(SaveGame, ReplicatedUsing=OnRep_SavedSlotIndex)
	int32 SavedSlotIndex;

private:
	UFUNCTION()
	void OnPlayerControllerPortConnectedWildcard(const TArray<UFMDeviceCablePortComponent*>& ControllerPorts);

	UFUNCTION()
	void OnPlayerControllerPortDisconnectedWildcard();

	UFUNCTION()
	void OnRep_SavedSlotIndex();

};

