// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FunctionalTest.h"
#include "CreativeFunctionalTest.generated.h"

class AActor;
class AFortMinigame;
class AGameModeBase;
class APlayerController;
class IFortSpatialGameplayInterface;
class UCreativeFunctionalTestConditionComponentBase;
class UFortControllerComponent_CreativeFunctionalTest;
class UFortLevelStreamComponent;
class UFortPlaylistAthena;
class ULevelRecordSpawner;
class UWorld;
enum class EFortMinigameState : uint8;

USTRUCT(BlueprintType)
struct FExpectedConsoleVariableForTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ExpectedConsoleVariableForTest")
	FString ConsoleVariable;

	UPROPERTY(EditAnywhere, Category="ExpectedConsoleVariableForTest")
	FString ConsoleVariableValue;

	UPROPERTY(Transient)
	FString OldConsoleVariableValue;

};

UCLASS(HideCategories=("Actor", "Input", "Rendering"))
class ACreativeFunctionalTest : public AFunctionalTest
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CreativeTest")
	bool CheckIfAllConditionsSatisifed() const;

	UFUNCTION(BlueprintCallable)
	bool GetCreatedDevices(TArray<AActor*>& OutCreatedDevices);

	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="DeviceClass", DynamicOutputParam="OutCreatedDevices"))
	bool GetCreatedDevicesOfClass(TSubclassOf<AActor> DeviceClass, TArray<AActor*>& OutCreatedDevices);

	UFUNCTION(BlueprintPure, Category="CreativeTest")
	APlayerController* GetPlayerControllerForTest() const;

	UFUNCTION(BlueprintNativeEvent)
	void HandleConditionSatisfiedChange(UCreativeFunctionalTestConditionComponentBase* Condition);

	UPROPERTY(BlueprintAssignable)
	FFunctionalTestEventSignature OnTestConditionSatisfied;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	bool ForceIgnoreErrorsAndWarnings;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TSubclassOf<AGameModeBase> RequiredGameMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TObjectPtr<UFortPlaylistAthena> RequiredPlaylist;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TSet<TSubclassOf<UFortControllerComponent_CreativeFunctionalTest>> RequiredControllerComponentClasses;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TScriptInterface<IFortSpatialGameplayInterface> SpatialGameplayActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TObjectPtr<AActor> DeviceSpawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TSoftObjectPtr<UWorld> DeviceMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TObjectPtr<AActor> PawnStartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	bool bShouldStartMinigame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	bool bShouldLevelStreamMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest")
	TArray<FExpectedConsoleVariableForTest> ExpectedConsoleVariablesForTest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CreativeTest", meta=(UIMax="10.0", UIMin="0.1"))
	float TimeScale;

private:
	UFUNCTION()
	void OnLevelRecordFinishSpawning(const TArray<AActor*>& NewlySpawnedActors);

	UFUNCTION()
	void OnMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UPROPERTY(Transient, Replicated)
	TArray<TObjectPtr<AActor>> CreatedDevices;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortLevelStreamComponent> LevelStreamComponent;

	UPROPERTY(Transient)
	TObjectPtr<ULevelRecordSpawner> ActiveRecordSpawner;

};

