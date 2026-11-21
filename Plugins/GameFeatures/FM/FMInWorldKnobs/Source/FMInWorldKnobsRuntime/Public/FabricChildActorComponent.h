// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "Math/MathFwd.h"
#include "FMDeviceCableModulatorPortComponent.h"
#include "FortLevelDuplicatableInterface.h"
#include "LevelSaveSpawnableInterface.h"
#include "FabricChildActorComponent.generated.h"

class AActor;
class AFMInWorldKnobActorBase;
class AFabricButtonBase;
class IFabricInteractable;
class UFMDeviceCableModulatorPortComponent;
class UFMDeviceCablePortComponent;

UCLASS(HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision", "Trigger", "PhysicsVolume"), ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMINWORLDKNOBSRUNTIME_API UFabricChildActorComponent : public UChildActorComponent, public ILevelSaveSpawnable, public ILevelDuplicatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	UFMDeviceCableModulatorPortComponent* CreateModulatorPortIfNeeded();

	UFUNCTION(BlueprintPure)
	AFabricButtonBase* GetChildActorAsFabricButton() const;

	UFUNCTION(BlueprintPure)
	TScriptInterface<IFabricInteractable> GetChildActorAsFabricInteractable() const;

	UFUNCTION(BlueprintPure)
	AFMInWorldKnobActorBase* GetChildActorAsInWorldKnobActorBase() const;

	UFUNCTION(BlueprintPure)
	FString GetKnobOptionKey() const;

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCableModulatorPortComponent> InWorldKnobModulatorPort;

private:
	UFUNCTION()
	void OnModulatorPortConnected(UFMDeviceCablePortComponent* ConnectedPort);

	UFUNCTION()
	void OnModulatorPortDisconnected(UFMDeviceCablePortComponent* DisconnectedPort);

	UPROPERTY(EditAnywhere, Category="FabricChildActorComponent")
	bool bUseScreenGrid;

	UPROPERTY(EditAnywhere, Category="FabricChildActorComponent", meta=(DisplayAfter="bUseScreenGrid", EditCondition="bUseScreenGrid"))
	FVector2D ScreenGridPosition;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="FabricChildActorComponent")
	FModulatorPortSaveData ModulatorPortSaveData;

	UPROPERTY(EditAnywhere, Category="FabricChildActorComponent")
	TSubclassOf<AActor> CableManagerClassForModulatorPorts;

};

