// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "FortHealthBarComponent.generated.h"

class ABuildingActor;
class UCurveFloat;
class UCurveLinearColor;

USTRUCT()
struct FFortHealthBarComponentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText DisplayText;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "Sockets", "Rendering", "Activation", "LOD", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortHealthBarComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Health Bar Component")
	FText GetHealthBarDisplayText() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Health Bar Component")
	void SetHealthBarDisplayText(FText NewDisplayText);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Health Bar Component")
	void SetHealthBarVisibility(bool bNewVisibleState);

	UFUNCTION(BlueprintCallable, Category="Health Bar Component")
	void SetHealthBarWidgetVisibility(bool bIsVisible);

protected:
	UFUNCTION()
	void OnRep_DisplayText();

	UFUNCTION()
	void OnRep_IsVisible();

	UPROPERTY()
	TObjectPtr<ABuildingActor> BuildingActorOwner;

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_DisplayText, Category="Display Info")
	FText DisplayText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, SaveGame, ReplicatedUsing=OnRep_IsVisible, Category="Display Info")
	bool bIsHealthBarVisible;

	UPROPERTY(EditDefaultsOnly, Category="Display Info")
	float MaxDistance;

	UPROPERTY(EditDefaultsOnly, Category="Display Info")
	TObjectPtr<UCurveFloat> ScaleOverDistanceCurve;

	UPROPERTY(EditDefaultsOnly, Category="Display Info")
	bool bClampToScreen;

	UPROPERTY(EditDefaultsOnly, Category="Display Info", meta=(EditCondition="bClampToScreen"))
	bool bShowClampToScreenArrow;

	UPROPERTY(EditDefaultsOnly, Category="Display Info")
	TObjectPtr<UCurveLinearColor> HealthBarColorCurve;

};

