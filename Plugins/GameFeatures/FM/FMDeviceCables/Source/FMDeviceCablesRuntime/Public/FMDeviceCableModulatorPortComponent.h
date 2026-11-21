// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "FMDeviceCablePortComponent.h"
#include "FMDeviceCableModulatorPortComponent.generated.h"

class UFMDeviceCableManagerComponent;
class UObject;

USTRUCT()
struct FMDEVICECABLESRUNTIME_API FModulatorPortSaveData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, SaveGame, Category="ModulatorPortSaveData", meta=(IgnoreForMemberInitializationTest))
	FGuid ConnectionGuid;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="ModulatorPortSaveData")
	TArray<FGuid> ConnectedGuids;

};

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), ClassGroup=("Harmonix"))
class FMDEVICECABLESRUNTIME_API UFMDeviceCableModulatorPortComponent : public UFMDeviceCablePortComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetDeviceCableManager(UFMDeviceCableManagerComponent* InDeviceCableManager);

protected:
	UPROPERTY(Replicated)
	FString AssociatedProperty;

	UPROPERTY(Transient)
	TWeakObjectPtr<UObject> AssociatedObject;

};

