// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "Quests/FortQuestObjectiveStatXPTable.h"
#include "FortCreativeAccoladesComponent.generated.h"

class AFortMinigame;
class AFortPlayerController;
class UTexture2D;

USTRUCT()
struct FAccoladeDeviceData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GUID;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	FString Weight;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativeAccoladesComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAccoladeWouldHaveGrantedSignature, const AFortPlayerController*, PlayerController);

public:
	UPROPERTY(BlueprintAssignable)
	FOnAccoladeWouldHaveGrantedSignature OnAccoladeWouldHaveGrantedDelegate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	FGuid GUID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	TSet<int32> ValidTeams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	TSet<int32> ValidClassSlots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	FGameplayTag XPAwardGameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	FGameplayTag SplashSizeGameplayTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortCreativeAccoladesComponent")
	EFortSimulatedXPSize SimulatedXpSize;

protected:
	UFUNCTION(BlueprintPure)
	bool CanGrantAccolade() const;

	UFUNCTION(BlueprintCallable)
	FString GetAccoladeJsonForLinkCode();

	UFUNCTION(BlueprintCallable)
	bool GrantAccolade(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	void OnPlayModeChanged(AFortMinigame* Minigame, const bool bNewIsInPlayMode);

};

