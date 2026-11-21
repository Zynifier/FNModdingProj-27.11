// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FortTypes.h"
#include "FrontEnd/ItemPreview/StateTransitionController.h"
#include "FortItemPreviewScene.generated.h"

class AFortCameraTargetPedestal;
class AItemPreviewScene;
class UCameraComponent;
class UChildActorComponent;
class UFortAccountItemDefinition;
class USceneComponent;

UENUM(BlueprintType)
enum class ESceneTransitionType : uint8
{
	NoTransition = 0,
	Clockwise = 1,
	CounterClockwise = 2,
};

USTRUCT(BlueprintType)
struct FInterpolatedTransitionCamera
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="InterpolatedTransitionCamera")
	FTransform CameraTransform;

	UPROPERTY(BlueprintReadWrite, Category="InterpolatedTransitionCamera")
	float FieldOfView;

};

USTRUCT(BlueprintType)
struct FSceneTransitionOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="SceneTransitionOptions")
	ESceneTransitionType Transition;

	UPROPERTY(BlueprintReadWrite, Category="SceneTransitionOptions")
	bool bKeepInputRotation;

};

UCLASS(MinimalAPI, NotBlueprintable)
class AFortItemPreviewSceneChanger : public AActor, public IFortUICameraPositionTargetInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API AItemPreviewScene* GetActiveScene();

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API AItemPreviewScene* GetPrimaryScene();

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API AItemPreviewScene* GetSceneTransitioningTo();

	UFUNCTION(BlueprintPure)
	FORTNITEUI_API bool IsSoundEnabled() const;

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnNewSceneRequested(const UFortAccountItemDefinition* PrimaryRequestedItem, const FSceneTransitionOptions& TransitionOptions);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnSetBackgroundMessageText(const FText& BackgroundMessageText);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnTargetRotationOffsetCanceled();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnTargetRotationOffsetSet(const FRotator& TargetRotationOffset);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnTargetZoomLevelCanceled();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnTargetZoomLevelSet(float TargetZoomLevel);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnUpdateBackgroundColor(bool bEnableAutotestBackground);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void TickPedestalRotationOffset();

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void TickZoomLevel();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="FortItemPreviewSceneChanger", meta=(EditInline="true"))
	TObjectPtr<UCameraComponent> TransitionCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="FortItemPreviewSceneChanger", meta=(EditInline="true"))
	TObjectPtr<UChildActorComponent> PrimarySceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="FortItemPreviewSceneChanger", meta=(EditInline="true"))
	TObjectPtr<UChildActorComponent> SecondarySceneComponent;

private:
	UPROPERTY(EditAnywhere, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess, Categories="UI.ItemPreview.SceneChanger"))
	FGameplayTag SceneChangerTag;

	UPROPERTY(EditAnywhere, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess))
	bool bHasEtherealBackground;

	UPROPERTY(EditAnywhere, Export, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<USceneComponent> SceneChangeRootComponent;

	UPROPERTY(Transient)
	TObjectPtr<AItemPreviewScene> PrimaryScene;

	UPROPERTY(Transient)
	TObjectPtr<AItemPreviewScene> SecondaryScene;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess))
	TObjectPtr<AItemPreviewScene> SceneTransitioningTo;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess))
	TObjectPtr<AItemPreviewScene> ActiveScene;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess))
	float ZoomLevel;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortItemPreviewSceneChanger", meta=(AllowPrivateAccess))
	FRotator PedestalRotationOffset;

};

UCLASS(BlueprintType, Blueprintable)
class AItemPreviewScene : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleItemShown(const UFortAccountItemDefinition* ItemViewed, AFortCameraTargetPedestal* Pedestal);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Export, Category="ItemPreviewScene", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UChildActorComponent> FocusCameraTargetComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortCameraTargetPedestal> FocusCameraTargetPedestal;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortCameraTargetPedestal>> BackgroundCameraTargetPedestals;

	UPROPERTY(Transient)
	FFortItemViewSettings ItemViewSettings;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortCameraTargetPedestal>> PedestalsLoading;

};

UINTERFACE()
class UFortPreviewSceneStateTransitionsListener : public UInterface
{
	GENERATED_BODY()
};

class IFortPreviewSceneStateTransitionsListener
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemsPendingTransitionOut(const FStateTransitionControllerHandle& TransitionController);

};

