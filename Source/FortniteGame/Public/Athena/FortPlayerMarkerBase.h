// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "FortPlayerMarkerBase.generated.h"

class UAthenaMapMarkerItemDefinition;
class UCurveFloat;
class UMaterialInstanceDynamic;
class UStaticMeshComponent;

UCLASS(Abstract, MinimalAPI)
class AFortPlayerMarkerBase : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void SpawnMarkerAnimTimelineProgress_Opacity(float Value);

	UFUNCTION()
	void SpawnMarkerAnimTimelineProgress_SpawnScale(float Value);

	UFUNCTION()
	void SpawnMarkerAnimTimelineProgress_SpawnVerticalScale(float Value);

	UFUNCTION(BlueprintCallable)
	void StartSpawnMarkerAnim();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnMarkerColorChanged(FLinearColor InColor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMarkerHidden();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMarkerPlaced();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayMarkerSound();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetupMarker(const FFortWorldMarkerData& MarkerData);

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerMarkerBase")
	FVector ImpactLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPlayerMarkerBase")
	FLinearColor Color;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerMarkerBase")
	TObjectPtr<UMaterialInstanceDynamic> MID_Main;

	UPROPERTY(BlueprintReadWrite, Category="FortPlayerMarkerBase")
	TObjectPtr<UMaterialInstanceDynamic> MID_Target;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerMarkerBase")
	TObjectPtr<UAthenaMapMarkerItemDefinition> CustomMarkerItemDefinition;

	UPROPERTY(EditAnywhere, Category="FortPlayerMarkerBase", meta=(ClampMin="0.000000"))
	float SpawnMarkerAnimLength;

	UPROPERTY(EditAnywhere, Category="FortPlayerMarkerBase")
	TObjectPtr<UCurveFloat> SpawnMarkerAnim_Opacity;

	UPROPERTY(EditAnywhere, Category="FortPlayerMarkerBase")
	TObjectPtr<UCurveFloat> SpawnMarkerAnim_SpawnScale;

	UPROPERTY(EditAnywhere, Category="FortPlayerMarkerBase")
	TObjectPtr<UCurveFloat> SpawnMarkerAnim_SpawnVerticalScale;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerMarkerBase")
	FFortWorldMarkerData CurrentMarkerData;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerMarkerBase", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

};

