// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "FortCosmeticReactivePreview.generated.h"

class AActor;
class AFortCosmeticReactivePreview;
class AFortPlayerPawn;
class UObject;
enum class EFCRP_LoopBehavior : uint8;

UENUM(BlueprintType)
enum class EFCRP_LoopBehavior : uint8
{
	// when the target is reached, stop updating.

	StopAtEnd = 0,
	// when the target is reached, change direction.

	PingPong = 1,
	// when the target is reached, keep the direction but reset to the start value

	WrapAround = 2,
};

USTRUCT()
struct FFCRP_LoopingUpdate
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UObject> Requester;

};

UCLASS(Abstract, MinimalAPI, meta=(DisplayName="FortCosmeticReactivePreview (FCRP)"))
class AFortCosmeticReactivePreview : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Reactive")
	virtual void DispatchReactEnd();

	UFUNCTION(BlueprintCallable, Category="Reactive")
	virtual void DispatchReactStart();

	UFUNCTION(BlueprintPure, Category="Reactive")
	const FCosmeticVariantInfo& GetVariantInfo() const;

	UFUNCTION(BlueprintCallable, Category="Fake Dynamic Stats", meta=(AdvancedDisplay="EndBehavior", DefaultToSelf="Requester"))
	void StartSmoothDynamicStat(UObject* Requester, float From, float To, float AtRate, EFCRP_LoopBehavior EndBehavior = EFCRP_LoopBehavior::PingPong);

	UFUNCTION(BlueprintCallable, Category="Fake Dynamic Stats", meta=(AdvancedDisplay="EndBehavior", DefaultToSelf="Requester"))
	void StartSteppedDynamicStat(UObject* Requester, int32 From, int32 To, int32 AtRate, EFCRP_LoopBehavior EndBehavior = EFCRP_LoopBehavior::PingPong);

protected:
	UFUNCTION()
	void OnBoundingActorEndedPlay(AActor* ActorEndingPlay, EEndPlayReason::Type Reason);

	UFUNCTION()
	void OnFortPlayerPawnFinishedCustomization(AFortPlayerPawn* Pawn);

	UPROPERTY()
	TArray<TObjectPtr<UObject>> PotentiallyResponsiveObjects;

	UPROPERTY()
	TArray<FFCRP_LoopingUpdate> ActiveLoops;

};

UCLASS(meta=(DisplayName="FCRP Basic Interface Calls"))
class AFortCosmeticReactivePreview_InterfaceWrapper : public AFortCosmeticReactivePreview
{
	GENERATED_BODY()

};

UINTERFACE()
class UReactivePreviewSupportInterface : public UInterface
{
	GENERATED_BODY()
};

class IReactivePreviewSupportInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Simulated Reactives")
	void PreviewReactiveSmoothUpdate(float CurrentValue, const FCosmeticVariantInfo& ChannelAndVariant, AFortCosmeticReactivePreview* Preview);

	UFUNCTION(BlueprintImplementableEvent, Category="Simulated Reactives")
	void PreviewReactiveSteppedUpdate(int32 CurrentValue, const FCosmeticVariantInfo& ChannelAndVariant, AFortCosmeticReactivePreview* Preview);

	UFUNCTION(BlueprintImplementableEvent, Category="Simulated Reactives")
	void StartPreviewReactiveResponse(const FCosmeticVariantInfo& ChannelAndVariant, AFortCosmeticReactivePreview* Preview);

	UFUNCTION(BlueprintImplementableEvent, Category="Simulated Reactives")
	void StopPreviewReactiveResponse(const FCosmeticVariantInfo& ChannelAndVariant, AFortCosmeticReactivePreview* Preview);

};

