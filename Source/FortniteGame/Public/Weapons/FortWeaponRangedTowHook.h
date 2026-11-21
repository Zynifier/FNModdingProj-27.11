// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Vehicle/FortTowhookModel.h"
#include "Weapons/FortWeaponRanged.h"
#include "FortWeaponRangedTowHook.generated.h"

class AActor;
class AFortPhysicsTowHook;
class UPrimitiveComponent;

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class AFortWeaponRangedTowHook : public AFortWeaponRanged
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="ActorDetachedFromTowHook", ScriptName="ActorDetachedFromTowHook"))
	void ActorDetachedFromTowHook(const AActor* DetachedActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AttachToTowHook(AActor* ActorToAttach);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void DetachActorsFromTowHook();

	UFUNCTION()
	void OnRep_TowHook();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetupTowhookAttachmentsOnServer(UPrimitiveComponent* FirstAttachedPrimitive, UPrimitiveComponent* SecondAttachedPrimitive);

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TowHook, Category="FortWeaponRangedTowHook")
	TObjectPtr<AFortPhysicsTowHook> TowHook;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TowHookModel")
	FTowhookParams TowHookParams;

};

