// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimNotifyState_SpawnProp.h"
#include "FortAnimNotifyState_SpawnPickaxe.generated.h"

UCLASS(HideCategories=("Object"))
class UFortAnimNotifyState_SpawnPickaxe : public UFortAnimNotifyState_SpawnProp
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

protected:
	virtual void GetActorPropOverride(AFortPawn* FortPawn, TSubclassOf<AActor>& InOutActorProp, USkeletalMesh*& InOutSkeletalMeshProp, UFortItemDefinition*& OutActorPropItemDefinition) override;
	virtual void OnActorPropSpawned(AActor* ActorPropInstance, UFortItemDefinition* ActorPropItemDefinition) override;

};

