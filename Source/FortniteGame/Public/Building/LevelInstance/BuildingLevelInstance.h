// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelInstance/LevelInstanceInterface.h"
#include "Misc/Guid.h"
#include "Building/BuildingActor.h"
#include "BuildingLevelInstance.generated.h"

class UWorld;

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class ABuildingLevelInstance : public ABuildingActor, public ILevelInstanceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_LevelInstanceSpawnGuid();

	FORTNITEGAME_API virtual const FLevelInstanceID& GetLevelInstanceID() const override;

	FORTNITEGAME_API virtual bool HasValidLevelInstanceID() const override;

	FORTNITEGAME_API virtual const FGuid& GetLevelInstanceGuid() const override;

	FORTNITEGAME_API virtual const TSoftObjectPtr<UWorld>& GetWorldAsset() const override;

	FORTNITEGAME_API virtual bool IsLoadingEnabled() const override;

#if WITH_EDITOR
	FORTNITEGAME_API virtual ULevelInstanceComponent* GetLevelInstanceComponent() const override;

	FORTNITEGAME_API virtual ELevelInstanceRuntimeBehavior GetDesiredRuntimeBehavior() const override;

	FORTNITEGAME_API virtual ELevelInstanceRuntimeBehavior GetDefaultRuntimeBehavior() const override;
#endif

protected:
	UPROPERTY(EditAnywhere, Category="Level", meta=(DisplayName="Level", NoCreate))
	TSoftObjectPtr<UWorld> WorldAsset;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LevelInstanceSpawnGuid)
	FGuid LevelInstanceSpawnGuid;

};

