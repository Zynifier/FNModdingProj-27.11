// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Athena/Markers/FortMarkableActorInterface.h"
#include "Athena/Markers/MarkedActorDisplayInfo.h"
#include "Building/BuildingTimeOfDayLights.h"
#include "BuildingProp.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FBuildingPropActorClassData : public FBuildingTimeOfDayLightsActorClassData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Tags", meta=(GetByRef))
	FGameplayTagContainer AnalyticsTags;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp : public ABuildingTimeOfDayLights, public IFortMarkableActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	FORTNITEGAME_API float BlueprintModifyIncomingDamage(float Damage, const FGameplayTagContainer& InTags, const FGameplayEffectContextHandle& EffectContext, AController* EventInstigator, AActor* DamageCauser);

	UFUNCTION(BlueprintNativeEvent, meta=(CallInEditor="true"))
	FORTNITEGAME_API FBox BP_GetComponentsBoundingBox(bool bNonColliding, bool bIncludeFromChildActors) const;

	UFUNCTION(BlueprintPure, meta=(CallInEditor="true"))
	FORTNITEGAME_API FBox GetBoundingBoxWithIgnoredComponents(TArray<UPrimitiveComponent*> IgnoredComponents, const bool bNonColliding = false, const bool bIncludeFromChildActors = false) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Marking")
	FORTNITEGAME_API const FMarkedActorDisplayInfo GetMarkerDisplayData() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Marking")
	FORTNITEGAME_API const FVector GetMarkerPositionOffset() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API bool IsBuildingVolume();

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void SetAsBuildingVolume(const bool bNewValue);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Marking")
	uint8 bDoNotBlockMarkerTraceWhenOverlappingPlayer : 1;

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Prop", meta=(DisplayName="GetEyesViewpoint"))
	FORTNITEGAME_API void BP_GetEyesViewpoint(FVector& OutLocation, FRotator& OutRotation) const;

	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(DisplayAfter="bSuppressInteractionWidget"))
	uint8 bSuppressSimpleInteractionWidgetForTouch : 1;

	UPROPERTY(EditDefaultsOnly, Category="Curie")
	uint8 bUseDamageSet : 1;

	UPROPERTY(EditDefaultsOnly, Category="BuildingProp")
	uint8 bIsBuildingVolume : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Marking")
	uint8 bCanBeMarked : 1;

	UPROPERTY(EditDefaultsOnly, Category="Marking")
	uint8 bBlockMarking : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	FGameplayTagContainer AnalyticsTags_DEPRECATED;
#endif

};

