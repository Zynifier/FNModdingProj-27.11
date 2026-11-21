// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "InputCoreTypes.h"
#include "Athena/SpecialActor/FortEventLevelTypes.h"
#include "FortEventLevelNavigationActor.generated.h"

class AFortEventLevelNavigationActor;
class AFortPlayerController;
class UFortEventLevelNavigationWidget;
class UFortGameStateComponent_EventLevel;
class UPrimitiveComponent;
class UStaticMeshComponent;
class UUserWidget;
class UWidgetComponent;

UENUM(BlueprintType)
enum class ENavOptionFallbackDir : uint8
{
	/** Four cardinal directions*/
	Left = 0,
	Right = 1,
	Up = 2,
	Down = 3,
	/** Number of navigation types*/
	Num = 4 UMETA(Hidden),
	/** Denotes an invalid navigation, more important used to denote no specified navigation*/
	Invalid = 5,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMcpInventoryUpdated);

USTRUCT(BlueprintType)
struct FFortEventLevelNavigationDisplayDetails
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortEventLevelNavigationDisplayDetails")
	FString NavActorName;

};

USTRUCT(BlueprintType)
struct FNavOptionFallback
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="NavOptionFallback")
	ENavOptionFallbackDir NavDir;

	UPROPERTY(EditInstanceOnly, Category="NavOptionFallback")
	TObjectPtr<AFortEventLevelNavigationActor> NavObj;

};

USTRUCT(BlueprintType)
struct FNavOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, Category="NavOptions", meta=(Categories="ERG.Camera"))
	FGameplayTag CameraTag;

	UPROPERTY(EditInstanceOnly, Category="NavOptions")
	TObjectPtr<AFortEventLevelNavigationActor> NavObjToLeft;

	UPROPERTY(EditInstanceOnly, Category="NavOptions")
	TObjectPtr<AFortEventLevelNavigationActor> NavObjToRight;

	UPROPERTY(EditInstanceOnly, Category="NavOptions")
	TObjectPtr<AFortEventLevelNavigationActor> NavObjToUp;

	UPROPERTY(EditInstanceOnly, Category="NavOptions")
	TObjectPtr<AFortEventLevelNavigationActor> NavObjToDown;

	UPROPERTY(EditInstanceOnly, Category="NavOptions", meta=(TitleProperty="NavDir"))
	TArray<FNavOptionFallback> NavFallbacks;

};

USTRUCT(BlueprintType)
struct FNavWidgetSettingContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="NavWidgetSettingContainer")
	FGameplayTagContainer CameraTags;

	UPROPERTY(EditAnywhere, Category="NavWidgetSettingContainer")
	FNavWidgetSettings WidgetSettings;

};

UCLASS(Abstract)
class AFortEventLevelNavigationActor : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool CanCommitNavigationRequest() const;

	UFUNCTION(BlueprintPure)
	FFortEventLevelNavigationDisplayDetails GetDisplayDetails() const;

	UFUNCTION(BlueprintPure)
	UFortGameStateComponent_EventLevel* GetOwningGameStateComp() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleObjectSpecialInteraction(FGameplayTag ActionTag, FGameplayTag CameraTag);

	UFUNCTION(BlueprintPure)
	bool HasPurchasedSeasonBook() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeForPlayer();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateWidgetVisibility(AFortPlayerController* PlayerController, bool bEnabled);

	UFUNCTION(BlueprintCallable)
	void UpdateBangState(FGameplayTag BangTacker, bool bShowBang);

protected:
	UFUNCTION()
	virtual void HandleMCPInventoryChanged(const TSet<FString>& TypesChanged, int64 ProfileRvn);

	UPROPERTY(EditAnywhere, Category="Display")
	FText NavDisplayName;

	UPROPERTY(EditAnywhere, Category="Nav Widget")
	TArray<FNavWidgetSettingContainer> NavWidgetSettings;

	UPROPERTY(EditAnywhere, Category="Nav Widget")
	FNavWidgetSettings DefaultNavWidgetSettings;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortEventLevelNavigationActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_NavigationWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortEventLevelNavigationActor", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_CursorTargetPosition;

	UPROPERTY(EditAnywhere, Category="Nav Widget")
	TSubclassOf<UFortEventLevelNavigationWidget> IndicatorWidgetClass;

	UPROPERTY(EditAnywhere, Category="Nav Widget")
	TSubclassOf<UUserWidget> CursorTargetWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="Scene Nav", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UStaticMeshComponent> DisplayMesh;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Scene Nav", meta=(Categories="ERG.NavObject"))
	FGameplayTag NavigationActorTag;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	FGameplayTagContainer CamerasThisNavObjectIsActiveFrom;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	TMap<FGameplayTag, FGameplayTag> CameraToNavigateTo;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	TMap<FGameplayTag, FGameplayTagContainer> AdditionalHighlightObjects;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	TMap<FGameplayTag, FGameplayTag> SpecialInteractionTags;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	bool bAutoClick;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	TArray<FNavOptions> CameraNavOptions;

	UPROPERTY(EditInstanceOnly, Category="Scene Nav")
	FString CalendarEventName;

	UPROPERTY(EditInstanceOnly, Category="Mobile")
	bool bAlwaysHighliteOnMobile;

	UPROPERTY(EditAnywhere, Category="Mobile")
	int32 MobileHighlightStencilValue;

	UPROPERTY(EditAnywhere, Category="Mobile")
	bool bOverrideMobileMeshSize;

	UPROPERTY(EditAnywhere, Category="Mobile")
	float MeshSizeOverrideScale;

	UPROPERTY(EditAnywhere, Category="Scene Nav")
	int32 CursorHoverHighlightStencilValue;

	UPROPERTY(EditAnywhere, Category="Scene Nav")
	bool bHideNavWidgetIfCantOpen;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> LevelController;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortGameStateComponent_EventLevel> GSC_StreamingLevelOwner;

	UPROPERTY(BlueprintAssignable)
	FOnMcpInventoryUpdated OnInventoryUpdated;

private:
	UFUNCTION()
	void HandleDisplayMeshBeginCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void HandleDisplayMeshClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
	void HandleDisplayMeshEndCursorOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
	void HandleDisplayMeshInputTouchEnd(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

};

