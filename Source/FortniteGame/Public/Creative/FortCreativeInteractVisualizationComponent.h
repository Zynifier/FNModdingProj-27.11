// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortCreativeInteractVisualizationComponent.generated.h"

class AFortMinigame;
class UCurveFloat;
class UMaterialInterface;
class UNavAreaBase;
class UShapeComponent;
class UStaticMesh;
class UStaticMeshComponent;

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeInteractVisualizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetRadius(const float InInteractRadius);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	TSubclassOf<UShapeComponent> CollisionComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	TSubclassOf<UNavAreaBase> CollisionComponentAreaClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	TObjectPtr<UCurveFloat> FloatCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	TObjectPtr<UMaterialInterface> StaticMeshMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	FVector ComponentRelativeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeInteractVisualizationComponent")
	float TransitionInterval;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Collision Component Created"))
	void BP_OnCollisionComponentCreated();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Collision"))
	void BP_OnUpdateCollision();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Visibility"))
	void BP_OnUpdateVisibility();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Visual Mesh Component Created"))
	void BP_OnVisualMeshComponentCreated();

	UFUNCTION(BlueprintPure)
	UShapeComponent* GetCollisionComponent() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetCurrentTime() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetInteractRadius() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	bool GetPendingShow() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetVisualizationDiameterDesired() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	float GetVisualizationDiameterStart() const;

	UFUNCTION(BlueprintPure)
	UStaticMeshComponent* GetVisualMeshComponent() const;

	UFUNCTION(BlueprintPure)
	bool HasInteractRadius() const;

private:
	UFUNCTION()
	void OnPlayModeChanged(AFortMinigame* InMinigame, bool bIsInPlayMode);

	UPROPERTY(BlueprintGetter=GetCurrentTime, Transient, Category="FortCreativeInteractVisualizationComponent", meta=(AllowPrivateAccess="true"))
	float CurrentTime;

	UPROPERTY(BlueprintGetter=GetVisualizationDiameterStart, Transient, Category="FortCreativeInteractVisualizationComponent", meta=(AllowPrivateAccess="true"))
	float VisualizationDiameterStart;

	UPROPERTY(BlueprintGetter=GetVisualizationDiameterDesired, Transient, Category="FortCreativeInteractVisualizationComponent", meta=(AllowPrivateAccess="true"))
	float VisualizationDiameterDesired;

	UPROPERTY(BlueprintGetter=GetInteractRadius, Transient, Category="FortCreativeInteractVisualizationComponent", meta=(AllowPrivateAccess="true"))
	float InteractRadius;

	UPROPERTY(BlueprintGetter=GetPendingShow, Transient, Category="FortCreativeInteractVisualizationComponent", meta=(AllowPrivateAccess="true"))
	bool bPendingShow;

};

