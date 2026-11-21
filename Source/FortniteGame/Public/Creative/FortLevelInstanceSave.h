// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Misc/Guid.h"
#include "LevelSaveSpawnableInterface.h"
#include "FortLevelInstanceSave.generated.h"

class AActor;
class AFortLevelInstanceSaveActor;
class UFortCreativeActorCollection;
class ULevelSaveRecord;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelInstanceAddedToSave, AFortLevelInstanceSaveActor*, LevelSaveActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelInstanceBeingDestroyed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelInstanceChanged, const AActor*, Instigator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelInstanceSaveContentCollectionChanged, const AActor*, Instigator, TSoftObjectPtr<UFortCreativeActorCollection>, ContentCollection);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLevelInstanceSaveNameChanged, FString, Name);

UCLASS(MinimalAPI, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortLevelInstanceSaveActor : public AInfo, public ILevelSaveSpawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetCachedActorCost() const;

	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UFortCreativeActorCollection> GetContentCollection() const;

	UFUNCTION(BlueprintPure)
	FGuid GetLevelInstanceGuid() const;

	UFUNCTION(BlueprintPure)
	bool GetSize(int32& OutSizeX, int32& OutSizeY, int32& OutHeight) const;

	UFUNCTION(BlueprintCallable)
	void Resave();

	UPROPERTY(SaveGame)
	TObjectPtr<ULevelSaveRecord> LevelSaveRecord;

	UPROPERTY(SaveGame)
	int32 SizeX;

	UPROPERTY(SaveGame)
	int32 SizeY;

	UPROPERTY(SaveGame)
	int32 Height;

	UPROPERTY(SaveGame)
	int32 CachedActorCost;

	UPROPERTY(SaveGame)
	TSoftObjectPtr<UFortCreativeActorCollection> ContentCollection;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceAddedToSave OnLevelInstanceAddedToSave;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceSaveNameChanged OnLevelInstanceSaveNameChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceChanged OnLevelInstanceSaveContentChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceChanged OnLevelInstanceSizeChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceSaveContentCollectionChanged OnLevelInstanceContentCollectionChanged;

	UPROPERTY(BlueprintAssignable)
	FOnLevelInstanceBeingDestroyed OnLevelInstanceBeingDestroyed;

private:
	UPROPERTY(VisibleAnywhere, Category="FortLevelInstanceSaveActor")
	FGuid SavedActorGuid;

};

