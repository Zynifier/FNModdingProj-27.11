// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UI/FortUIManagerInterface.h"
#include "FortUIManager.generated.h"

class UFortLocalPlayer;
class UFortUIManager;
class UUserWidget;

UENUM()
enum class ELetoDisplayMode : uint8
{
	// Fullscreen viewport for the primary player only, regardless of the other player's existence

	PrimaryOnly = 0,
	// Fullscreen viewport for one player, but players can swap control over who's is displayed and who's is dormant

	SingleToggle = 1,
	// Viewports displayed simultaneously for both players

	Simultaneous = 2,
};

USTRUCT()
struct FFortRootViewportLayoutInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortLocalPlayer> LocalPlayer;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> RootLayout;

};

UCLASS(Abstract, Config=Game, MinimalAPI, BlueprintType, Blueprintable)
class UFortUIManager : public UObject, public IFortUIManagerInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="FortUIManager")
	TSoftClassPtr<UUserWidget> LayoutClass;

	UPROPERTY(EditAnywhere, Category="FortUIManager")
	bool bUseLegacyInputSystem;

	UPROPERTY(Transient)
	TArray<FFortRootViewportLayoutInfo> RootViewportLayouts;

private:
	UPROPERTY(Config, meta=(AssetBundles="Client"))
	TSoftClassPtr<UFortUIManager> UIManagerClass;

};

