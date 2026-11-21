// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "PhysicsEngine/ClusterUnionActor.h"
#include "Physics/FortPhysicsObjectInterface.h"
#include "FortClusterUnionActor.generated.h"

class UFortPhysicsObjectComponent;

UCLASS()
class FORTNITEGAME_API AFortClusterUnionActor : public AClusterUnionActor, public IFortPhysicsObjectInterface, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	AFortClusterUnionActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(Transient)
	FGameplayTagContainer GameplayTags;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPhysicsObjectComponent> PhysicsObjectComponent;

};

