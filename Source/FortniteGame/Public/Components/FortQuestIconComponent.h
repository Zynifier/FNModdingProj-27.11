// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent_PinQuest.h"
#include "FortInteractInterface.h"
#include "UI/FortElevationData.h"
#include "FortQuestIconComponent.generated.h"

class AFortPlayerController;
class IFortInteractInterface;
class UFortMiniMapIndicator;
class UObject;
class UUserWidget;

USTRUCT(BlueprintType)
struct FFortMapIconDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TObjectPtr<UObject> MapIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TObjectPtr<UObject> MapIconPinned;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon")
	FVector2D IconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon")
	bool bUseIconSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon")
	FVector2D IconMaterialSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Icon")
	FLinearColor Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	TSubclassOf<UFortMiniMapIndicator> MinimapIndicatorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour", meta=(AllowedClasses="/Script/FortniteUI.AthenaQuestActorIndicator", DisplayName="In-World Indicator Class"))
	TSoftClassPtr<UUserWidget> InWorldIndicatorSoftClass;

	UPROPERTY(Transient)
	TSubclassOf<UUserWidget> InWorldIndicatorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bIsVisibleOnMiniMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bIsVisibleOnMap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bIsVisibleInWorld;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bStartVisible;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	FScalableFloat ViewDistanceRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour", meta=(InlineEditConditionToggle))
	bool bOverrideMaxViewDistanceForInWorldIndicator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour", meta=(EditCondition="bOverrideMaxViewDistanceForInWorldIndicator"))
	float InWorldIndicatorMaxViewDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour", meta=(InlineEditConditionToggle))
	bool bAllowMinViewDistanceForInWorldIndicator;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour", meta=(EditCondition="bAllowMinViewDistanceForInWorldIndicator"))
	float InWorldIndicatorMinViewDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bIncludeZOffsetInDistanceChecks;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bIgnoreActorRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	FVector LocationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	bool bUseWorldSpaceForOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	FElevationArrowData ElevationArrowData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Behaviour")
	int32 Priority;

};

UCLASS(MinimalAPI, BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortQuestIconComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="MiniMap Data")
	float GetViewDistanceRadius() const;

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIcon(UObject* MiniMapIcon);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIconLocationOffset(const FVector& LocationOffset);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIconPinned(UObject* PinnedIcon);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIconScale(const FVector2D& IconScale);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIconVisibilityInWorld(const bool bVisible);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIconVisibilityOnMap(const bool bVisible);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetIconVisibilityOnMiniMap(const bool bVisible);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data", meta=(ClampMax="1000000", ClampMin="0.0"))
	void SetViewDistanceRadius(const float ViewDistance);

	UFUNCTION(BlueprintCallable, Category="MiniMap Data")
	void SetVisibility(const bool bVisible);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mini Map Data")
	bool bControlVisibilityFromOwnerQuestObjectiveState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mini Map Data")
	bool bInteractiveStateRequiredForVisibility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mini Map Data", meta=(EditCondition="bInteractiveStateRequiredForVisibility"))
	TEnumAsByte<TInteractionType> ExplicitInteractionTypeToTest;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Mini Map Data")
	FFortMapIconDefinition MapIconData;

private:
	UFUNCTION()
	void HandlePinnedQuestChanged(const FAthenaPinnedQuestData& PinnedQuestData);

	UFUNCTION()
	void OnOwnerCustomUpdateObjective(AFortPlayerController* PlayerController, int32 AchievedCount, int32 RequiredCount);

	UFUNCTION()
	void OnOwnerObjectiveUpdated(const AFortPlayerController* PlayerController, const bool bQuestCompleted);

	UFUNCTION()
	void OnOwnerQuestNotReady(AFortPlayerController* PlayerController);

	UFUNCTION()
	void OnOwnerQuestReady(AFortPlayerController* PlayerController);

	UFUNCTION()
	void OnQuestStageChanged(const AFortPlayerController* PlayerController, const int32 UpdatedQuestStage);

	UFUNCTION()
	void PerformVisibilityDistanceCheck();

	UPROPERTY()
	TScriptInterface<IFortInteractInterface> CachedOwnerInteractInterface;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UUserWidget* InWorldIndicator;

};

