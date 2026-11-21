// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/Components/FortConvertUtils.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_Convert.generated.h"

class AActor;
class AController;
class AFortPawn;
class AFortPlayerPawn;
class AFortPlayerState;
class APawn;
class UFortAbilitySet;
class UFortAthenaAIRuntimeParameters_AIConvert;
class UFortItemDefinition;
class UFortPawnComponent_Convert;
class UPrimitiveComponent;
class USoundBase;
class UUserWidget;
enum class EConvertedType : uint8;
enum class EUnconvertReason : uint8;
enum class PingCommandType : uint8;

UENUM(BlueprintType)
enum class EAIPingCommandType : uint8
{
	None = 0,
	PingGoTo = 1,
	PingHoldPosition = 2,
	PingBackToMe = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FConvertedEvent, AFortPawn*, InstigatorPawn, AFortPawn*, ConvertedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHideTamedIndicatorEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPingCommandEvent, PingCommandType, CommandType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPawnConvertEvent, AFortPawn*, ConvertedPawn);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPawnUnconvertEvent, AFortPawn*, UnconvertedPawn, EUnconvertReason, UnconvertReason);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FShowTamedIndicatorEvent, bool, bCanShowIndicator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUnconvertedEvent, AFortPawn*, UnconvertedPawn, EUnconvertReason, UnconvertReason);

USTRUCT()
struct FConvertedComponentInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EConvertedType ConvertedType;

	UPROPERTY(Export)
	TArray<TWeakObjectPtr<UFortPawnComponent_Convert>> ConvertedComponentList;

};

USTRUCT()
struct FConverterPlayerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerState> ConverterPlayerState;

	UPROPERTY(Transient)
	EUnconvertReason LastUnconvertReason;

};

USTRUCT()
struct FTaggedConversionAbilities
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortAbilitySet> AbilitySet;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_Convert : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Convert")
	void AddToPreConversionFactions(const FGameplayTag& FactionTag);

	UFUNCTION(BlueprintPure, Category="Convert")
	float CalculateConvertDamageFromPickupTags(const FGameplayTagContainer& Tags, float Level) const;

	UFUNCTION(Client, Reliable)
	void ClientRegisterConvertPawn(AFortPawn* ConvertedPawn);

	UFUNCTION(BlueprintPure, Category="Convert")
	const TArray<AFortPawn*> GetConvertedPawns(const EConvertedType SpecificConvertedType = EConvertedType::All) const;

	UFUNCTION(BlueprintPure, Category="Convert")
	EConvertedType GetConvertedType() const;

	UFUNCTION(BlueprintPure, Category="Convert")
	AFortPlayerPawn* GetConverterPawn() const;

	UFUNCTION(BlueprintPure, Category="Convert")
	int32 GetMaxConvertedCreature() const;

	UFUNCTION(BlueprintPure, Category="Convert")
	int32 GetMaxConvertedNPC() const;

	UFUNCTION(BlueprintPure, Category="Convert")
	int32 GetNumConvertedPawns(const EConvertedType SpecificConvertedType = EConvertedType::All) const;

	UFUNCTION(BlueprintPure, Category="Convert")
	bool GetOnlyLeaderInteraction() const;

	UFUNCTION(BlueprintPure)
	FLinearColor GetUIColor() const;

	UFUNCTION(BlueprintCallable, Category="Convert")
	void HideIndicatorMarker();

	UFUNCTION(NetMulticast, Reliable)
	void OnPingCommand(PingCommandType CommandType);

	UFUNCTION(BlueprintCallable, Category="Convert")
	void RemoveFromPreConversionFactions(const FGameplayTag& FactionTag);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRequestReleaseAllConvertedPawns(const EConvertedType SpecificConvertedType, const EUnconvertReason UnconvertReason);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRequestReleaseLastConvertedPawns(const EConvertedType SpecificConvertedType, const EUnconvertReason UnconvertReason);

	UFUNCTION(BlueprintCallable, Category="Convert")
	void SetCanBeConverted(const bool bInCanBeConverted);

	UFUNCTION(BlueprintCallable, Category="Convert")
	void ShowIndicatorMarker();

	UFUNCTION(BlueprintCallable, Category="Convert")
	static void TriggerConversion(AFortPawn* Converter, AFortPawn* Converted, const bool bCanSteal = false);

	UFUNCTION(BlueprintCallable, Category="Convert")
	static void TriggerUnconversion(AFortPawn* Unconverter, AFortPawn* Unconverted);

protected:
	UFUNCTION()
	void HandleControllerChanged(APawn* Pawn, AController* OldController, AController* NewController);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPawnComponent_Convert")
	TMap<EConvertedType, FLinearColor> ConvertedTypeColorMap;

private:
	UFUNCTION(BlueprintCallable, Category="Convert")
	void AppendConverterAbilitiesToAssignConverted(UFortAbilitySet* AbilitySetForConverted);

	UFUNCTION(BlueprintCallable, Category="Convert")
	void AppendConverterAbilitiesToAssignConvertedWithTags(const FGameplayTagQuery& TagsMatchingConverted, UFortAbilitySet* AbilitySetForConverted);

	UFUNCTION()
	void OnConvertedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnConverterStartedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void OnConverterStoppedEmote(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void OnConverterTeamChange();

	UFUNCTION()
	void OnRep_ConverterPlayerInfo();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanConvert;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanBeConverted;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat CanBeConvertedFromDBNO;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxConvertedNPC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat MaxConvertedCreature;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	FScalableFloat ConvertTimeFromDBNO;

	UPROPERTY(EditDefaultsOnly, Category="Convert", meta=(AllowPrivateAccess="true"))
	TObjectPtr<USoundBase> ConvertInteractionSound;

	UPROPERTY(EditAnywhere, Category="Convert")
	TSubclassOf<UUserWidget> IndicatorMarkerWidgetClass;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FConvertedEvent OnConvertedEvent;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FUnconvertedEvent OnUnconvertedEvent;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FPawnConvertEvent OnConvertEvent;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FPawnUnconvertEvent OnUnconvertEvent;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FShowTamedIndicatorEvent OnShowConvertedIndicator;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FHideTamedIndicatorEvent OnHideConvertedIndicator;

	UPROPERTY(BlueprintAssignable, Category="Convert Events", meta=(AllowPrivateAccess="true"))
	FOnPingCommandEvent OnPingCommandEvent;

	UPROPERTY(Transient, Replicated)
	uint8 bCanConvert : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bCanBeConverted : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bCanBeConvertedFromDBNO : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Convert", meta=(AllowPrivateAccess="true"))
	uint8 bCanShowMarker : 1;

	UPROPERTY(Transient)
	uint8 bShouldShowIndicatorMarker : 1;

	UPROPERTY(Transient)
	uint8 bOwnerPawnDied : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ConverterPlayerInfo)
	FConverterPlayerInfo ConverterPlayerInfo;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerState> PreviousConverterPlayerState;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_AIConvert> CachedAIConvertParameters;

	UPROPERTY(Transient, Replicated)
	TArray<FConvertedComponentInfo> ConvertedPawnComponents;

	UPROPERTY(Transient, Replicated)
	TArray<TWeakObjectPtr<AFortPlayerState>> PreviousConverters;

	UPROPERTY(Transient)
	EConvertedType ConvertedType;

	UPROPERTY(Transient)
	TArray<FTaggedConversionAbilities> ConverterSpecificAbilitiesAddedToConverted;

	UPROPERTY(Replicated)
	bool bOnlyLeaderInteraction;

};

