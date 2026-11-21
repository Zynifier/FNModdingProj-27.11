// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Misc/Guid.h"
#include "FortSaveFileBuildingInstructionsHandler.generated.h"

class ABuildingActor;
class AFortPlayerController;
class UFortBuildingInstructions;

USTRUCT()
struct FFortDestroyedActorRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid ActorGuid;

	UPROPERTY()
	TSubclassOf<ABuildingActor> ActorClass;

	UPROPERTY()
	FTransform ActorTransform;

};

USTRUCT()
struct FFortBuildingActorArray
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FFortDestroyedActorRecord> ActorRecords;

};

UCLASS(Config=Game, BlueprintType, Blueprintable)
class AFortSaveFileBuildingInstructionsHandler : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SavedInstructions")
	bool AreBuildingsLoaded();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SavedInstructions")
	void LoadBuildings(AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SavedInstructions")
	bool ResetBuildings();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="SavedInstructions")
	bool SaveBuildings(AFortPlayerController* FortPC);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SavedInstructions")
	FString SaveFileName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SavedInstructions")
	FVector LoadedBuildingsScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SavedInstructions")
	FVector LoadedBuildingsAdditionalTranslation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SavedInstructions")
	uint8 bUseAbsoluteCoordinates : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SavedInstructions")
	uint8 bTrackDestroyedBuildings : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SavedInstructions")
	TSoftObjectPtr<UFortBuildingInstructions> DefaultBuildingInstructions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SavedInstructions")
	uint8 bLoadInvisible : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SavedInstructions")
	uint8 bDespawnOnBuildingsSpawned : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SavedInstructions")
	uint8 bSpawnBuildingsAutomaticallyAfterLoad : 1;

protected:
	UPROPERTY(Transient)
	FUniqueNetIdRepl OperationUserId;

};

