// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "Components/ActorComponent.h"
#include "FortPlayerConversationUIComponent.generated.h"

class UCommonActivatableWidget;
class UDynamicUIScene;
class UUserWidget;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerConversationUIComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnMinigameStarted();

	UPROPERTY(EditAnywhere, Category="Classes", meta=(AllowedClasses="/Script/FortniteConversationUI.FortConversationScreen"))
	TSoftClassPtr<UCommonActivatableWidget> DialogWidgetSoftClass;

	UPROPERTY(EditAnywhere, Category="Classes", meta=(AllowedClasses="/Script/FortniteConversationUI.FortConversationMarker"))
	TSoftClassPtr<UUserWidget> DialogMarkerSoftClass;

	UPROPERTY(EditAnywhere, Category="Classes", meta=(AllowedClasses="/Script/FortniteConversationUI.MobileConversationScreen"))
	TSoftClassPtr<UCommonActivatableWidget> MobileDialogWidgetSoftClass;

	UPROPERTY(EditAnywhere, Category="Classes")
	TArray<TObjectPtr<UDynamicUIScene>> SpectatorConversationScenes;

	UPROPERTY(EditAnywhere, Category="Classes")
	TArray<TObjectPtr<UDynamicUIScene>> SpectatorMobileConversationScenes;

	UPROPERTY(Transient)
	TSubclassOf<UUserWidget> DialogWidgetClass;

	UPROPERTY(Transient)
	TSubclassOf<UUserWidget> DialogMarkerClass;

	UPROPERTY(Transient)
	FUserWidgetPool DialogWidgetPool;

};

