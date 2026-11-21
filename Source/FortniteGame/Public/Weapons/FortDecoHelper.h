// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Building/BuildingSMActor.h"
#include "Building/BuildingTypes.h"
#include "FortDecoHelper.generated.h"

class AActor;
class ABuildingActor;
class ABuildingSMActor;
class AFortDecoPreview;
class AFortDecoTool;
class UFortDecoItemDefinition;

USTRUCT()
struct FDecoPlacementState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector Start;

	UPROPERTY()
	FVector End;

	UPROPERTY()
	FVector RawLocation;

	UPROPERTY()
	FVector Normal;

	UPROPERTY()
	FQuat AbsoluteRotation;

	UPROPERTY()
	FVector GridLocation;

	UPROPERTY()
	FVector ExtraPieceLocation;

	UPROPERTY()
	FVector PreviousLocation;

	UPROPERTY()
	FVector FallbackLocation;

	UPROPERTY()
	TWeakObjectPtr<AActor> LastHitActor;

	UPROPERTY()
	TWeakObjectPtr<ABuildingSMActor> CurrentBuildingActorAttachment;

	UPROPERTY()
	FVector CreateBuildingLocation;

	UPROPERTY()
	FRotator CreateBuildingRotation;

	UPROPERTY()
	TEnumAsByte<EFortDecoPlacementQueryResults::Type> CanPlaceState;

};

UCLASS()
class AFortDecoHelper : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetInFallbackPosition() const;

	UFUNCTION(BlueprintPure)
	bool IsInValidPlacementSpot(bool bTestingForVisuals) const;

	UPROPERTY(BlueprintReadWrite, Category="FortDecoHelper")
	TWeakObjectPtr<AFortDecoTool> DecoTool;

	UPROPERTY(BlueprintReadOnly, Category="FortDecoHelper")
	float DecoToolReach;

	UPROPERTY(BlueprintReadOnly, Category="FortDecoHelper")
	TEnumAsByte<EBuildingAttachmentType> CurrentAttachmentType;

	UPROPERTY(BlueprintReadOnly, Category="FortDecoHelper")
	TEnumAsByte<EPlacementType::Type> CurrentPlacementType;

protected:
	UPROPERTY(BlueprintReadWrite, Category="FortDecoHelper")
	TObjectPtr<AFortDecoPreview> DecoPreview;

	UPROPERTY()
	TSubclassOf<ABuildingActor> PlacementActorClass;

	UPROPERTY(BlueprintReadOnly, Category="FortDecoHelper")
	TObjectPtr<UFortDecoItemDefinition> DecoItemDefinition;

	UPROPERTY()
	FVector LocationData[2];

	UPROPERTY()
	FRotator RelativeRotationData[2];

	UPROPERTY()
	FRotator AbsoluteRotationData[2];

	UPROPERTY()
	float ScaleData[2];

	UPROPERTY()
	FDecoPlacementState PlacementInfo;

	UPROPERTY()
	bool bInFallbackPosition;

	UPROPERTY()
	float FallbackTinyScale;

	UPROPERTY()
	TEnumAsByte<EFortDecoPlacementQueryResults::Type> CanPlaceState;

	UPROPERTY(BlueprintReadWrite, Category="FortDecoHelper")
	FText CustomPlacementText;

	UPROPERTY(BlueprintReadWrite, Category="FortDecoHelper")
	float DesiredRelativeRotation;

	UPROPERTY()
	FVector DirectionChange;

	UPROPERTY(BlueprintReadOnly, Category="FortDecoHelper")
	float GridSnapSize;

	UPROPERTY()
	FRotator FreeFloorPlacementRelativeRotationOffset;

};

