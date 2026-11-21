// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AI/Components/FortConvertUtils.h"
#include "Athena/AI/Components/PingCommandUtils.h"
#include "Athena/Markers/FortWorldMarkerConfirmation.h"
#include "Athena/Markers/FortWorldMarkerTypeEnum.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "FortWorldMarker.generated.h"

class AActor;
class AFortPawn;
class AFortPickup;
class AFortPlayerMarkerBase;
class AFortPlayerState;
class UAthenaMarkerComponent;
class UFortItemDefinition;
class UFortWorldItemDefinition;
class UFortWorldMarker;
class UUserWidget;

USTRUCT()
struct FFortClientMarkerRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 InstanceID;

	UPROPERTY()
	EFortWorldMarkerType MarkerType;

	UPROPERTY()
	FVector BasePosition;

	UPROPERTY()
	FVector BasePositionOffset;

	UPROPERTY()
	FVector WorldNormal;

	UPROPERTY()
	TObjectPtr<AActor> MarkedActor;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY()
	uint8 bIncludeSquad : 1;

	UPROPERTY()
	uint8 bUseHoveredMarkerDetail : 1;

	UPROPERTY()
	uint8 bHeldMarkerInput : 1;

	UPROPERTY()
	PingCommandType PingCommand;

	UPROPERTY()
	EConvertedType TargetConvertedType;

};

USTRUCT(BlueprintType)
struct FMarkerID
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PlayerID;

	UPROPERTY()
	int32 InstanceID;


	FORTNITEGAME_API bool operator==(const FMarkerID& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FMarkerID& Value);
};

USTRUCT(BlueprintType)
struct FFortWorldMarkerData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	FMarkerID MarkerID;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	TObjectPtr<AFortPlayerState> Owner;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	EFortWorldMarkerType MarkerType;

	UPROPERTY()
	FVector BasePosition;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	FVector BasePositionOffset;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	FVector WorldNormal;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	TObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	int32 ItemCount;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	TWeakObjectPtr<AActor> MarkedActor;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	TSoftClassPtr<AActor> MarkedActorClass;

	UPROPERTY()
	bool bIncludeSquad;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	FGameplayTag MarkerTag;

	UPROPERTY(BlueprintReadOnly, Category="FortWorldMarkerData")
	bool bUseHoveredMarkerDetail;

private:
	UPROPERTY()
	PingCommandType PingCommand;

	UPROPERTY()
	EConvertedType TargetConvertedType;

	UPROPERTY()
	FFortWorldMarkerConfirmationContainer ConfirmationContainer;

	UPROPERTY()
	uint8 bHasCustomDisplayInfo : 1;

	UPROPERTY()
	uint8 bHeldMarkerInput : 1;

	UPROPERTY()
	FMarkedActorDisplayInfo CustomDisplayInfo;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<UFortWorldMarker> MarkerInstance;

};

USTRUCT()
struct FFortWorldMarkerContainer : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortWorldMarkerData> Markers;

	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMarkerComponent> OwningComponent;

};

UCLASS(MinimalAPI)
class UFortWorldMarker : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CancelMarker();

	UFUNCTION(BlueprintPure)
	UUserWidget* GetMarkerWidget() const;

	UFUNCTION(BlueprintCallable)
	bool ToggleMarkerConfirmation(int32 InPlayerId, FLinearColor InPinColor);

private:
	UFUNCTION()
	void ActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void PickedUp(AFortPickup* SelfActor, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation);

	UFUNCTION()
	void PlayerStateDestroyed(AActor* DestroyedActor);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaMarkerComponent> MarkerComponent;

	UPROPERTY()
	FFortWorldMarkerData MarkerDataCache;

	UPROPERTY()
	TObjectPtr<AFortPlayerMarkerBase> MarkerActor;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> MarkerWidget;

};

