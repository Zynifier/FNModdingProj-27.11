// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Input/FortActionKeyMapping.h"
#include "FortInputData.generated.h"

class UFortInputData;
enum class EFortInputActionGroup : uint8;

UENUM()
enum class EFortInputGameMode : uint8
{
	SaveTheWorld = 0,
	Athena = 1,
};

USTRUCT()
struct FScreenLabelText
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ScreenLabelText")
	FText NormalText;

	UPROPERTY(EditAnywhere, Category="ScreenLabelText")
	FText RichText;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortInputData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAbility1Label() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAbility2Label() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAbility3Label() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAimDownSightsHeavyMeleeLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAimDownSightsLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAttackConfirmLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetAutoSprintLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetBuildingEditResetLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetChangeMaterialLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetChatHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetCraftAmmoHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetCrouchLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetDeployHoverboardLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetEditBuildingPieceHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetEmoteLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetEmoteOrQuickChatOrSpotEnemyLabel() const;

	UFUNCTION(BlueprintPure, Category="Input Data")
	static UFortInputData* GetFortInputDataForBlueprint();

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGadget1Label() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGadget2Label() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGameMenuLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadChangeMaterialOrTrapPickerLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadFloorSelectAndPlaceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadRoofSelectAndPlaceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadStairSelectAndPlaceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadTrapPickerHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadTrapSelectAndPlaceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetGamepadWallSelectAndPlaceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetHarvestWeaponHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetHarvestWeaponLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetInteractTapHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetJumpLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetLookLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetMoveLabel();

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetNextBuildingPieceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetNextWeaponLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetNextWeaponTapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPickTrapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPickTrapTapHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPickTrapTapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPlaceBuildingOrTrapConfirmLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPreviousBuildingPieceLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPreviousWeaponLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetPreviousWeaponTapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetReloadLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetReloadTapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetRepairHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetRepairLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetRepairOrImproveLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetRotateBuildingLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetRotateBuildingTapRepairHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetScreenLabel(const FName PresetName, const EFortInputActionGroup InputActionGroup, const FName ActionName, const bool bRichText = false) const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetSprintLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetSwitchQuickbarLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetSwitchQuickBarTapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetToggleFullScreenMapLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetToggleInventoryLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetTrapInventoryHoldLabel() const;

	UFUNCTION(BlueprintPure, Category="Controller Configuration Labels")
	FText GetUseOrReloadLabel() const;

private:
	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigDName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigEName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigFName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigGName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigDAthenaName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigEAthenaName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigFAthenaName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigGAthenaName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigHAthenaName;

	UPROPERTY(EditAnywhere, Category="Input Configurations")
	FName ConfigCustomAthenaName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility1Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility2Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility1AName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility1BName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility2AName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility2BName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility3AName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadAbility3BName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadPreviousBuildingName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadNextBuildingName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadBuildingSlot1Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadBuildingSlot2Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadBuildingSlot3Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadBuildingSlot4Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadToggleHarvestWeaponName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadToggleHarvestWeaponOrAltInteractName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadToggleCreativePhoneWeaponName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadToggleHarvestOrHoldCreativePhoneName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadSelectPreviousWeaponName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadSelectNextWeaponName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadQuickWeaponName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadQuickWeapon1Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadQuickWeapon2Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadQuickWeapon3Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadQuickWeapon4Name;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadHoldToBuildName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadCreativeQuickbarSelectNextName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadCreativeQuickbarSelectPreviousName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadNextWeaponOrHarvestHoldName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadNextWeaponOrAltInteractOrHarvestHoldName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadTapSelectPreviousWeaponForChordAbilities;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadTapSelectNextWeaponForChordAbilities;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadTrapPickerName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadUseOrTrapPickerName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadUseOrTrapPickerAndPlaceName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadChangeMaterialOrHarvestHoldName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadSwitchModeOrEditBuildingName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadImproveOrRotateBuildingPieceName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadRepairHoldOrRotateBuildingPieceName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName GamepadPerformBuildingEditInteractionOrCancelPersonalVehicleName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName DBNOCarryHoistName;

	UPROPERTY(EditAnywhere, Category="Gamepad Action Bindings")
	FName AlternateInteractCarryName;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey1Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey2Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey3Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey4Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey5Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey6Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey7Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey8Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey9Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKey10Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF1Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF2Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF3Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF4Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF5Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF6Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF7Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF8Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF9Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF10Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF11Name;

	UPROPERTY(EditAnywhere, Category="Quickbar Action Bindings")
	FName HotbarKeyF12Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarActivateClutchName;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey1Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey2Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey3Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey4Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey5Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey6Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey7Name;

	UPROPERTY(EditAnywhere, Category="Creative Quickbar Action Bindings")
	FName CreativeQuickbarKey8Name;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName TrapPickerName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ChangeMaterialName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BuildConfirmName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName PerformBuildingEditInteractionName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName PerformBuildingImprovementInteractionName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName PickerConfirmName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName EndOfZonePickerConfirmName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName PickerCancelName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName EmotePickerName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName SquadQuickChatPickerName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName SwitchQuickBarName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName UseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName UseOrReloadName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ReloadName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName InventoryOrChatHoldName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName FireName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName TargetName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ToggleTargetModeName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName RotatePrimitiveClockwiseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ToggleFullScreenMapName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleFullScreenMapName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleFullScreenMapWhileBuildingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleFullScreenMapWhileEditingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ToggleInventoryName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleInventoryName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleInventoryWhileBuildingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleInventoryWhileEditingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName JumpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadJumpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CrouchName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CrouchWhileBuildingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CrouchWhileEditingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CrouchOrRepairName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CrouchOrRepairWhileBuildingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CrouchOrRepairWhileEditingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ToggleQuestVOMuteName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName QuickHealingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ShoppingCartCoastName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CannonShootName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadCannonShootName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CannonCoastName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadCannonCoastName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GolfCartEBrakeName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadGolfCartEBrakeLeftName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadGolfCartEBrakeRightName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadGolfCartForwardName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadGolfCartReverseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GolfCartHonkName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName JackalBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName JackalJumpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadJackalJumpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadJackalBoostLeftName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadJackalBoostRightName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName JackalUseOrExitName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadJackalExitName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadJackalUseOrExitName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName HamsterballBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName HamsterballShootName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName HamsterballExtendName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadHamsterballBoostLeftName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadHamsterballBoostRightName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadHamsterballShootName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadHamsterballExtendName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplanePitchForward;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplanePitchForwardSecondary;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneRollRightName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneRollLeftName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneRollInvertName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneStartEngineName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneStopEngineName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneTaxiBackwardsName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneShootName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName BiplaneFreelookName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplanePitchForward;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneRollRightName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneRollLeftName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneRollInvertName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneStartEngineName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneStopEngineName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneTaxiBackwardsName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadBiplaneShootName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName HoagieBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadHoagieBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName OstrichBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadOstrichBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName OstrichJumpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadOstrichJumpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName OstrichPrimaryFireName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadOstrichPrimaryFireName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName OstrichSecondaryFireName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadOstrichSecondaryFireName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName OstrichShieldBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadOstrichShieldBoostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName OstrichSelfDestructName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadOstrichSelfDestructName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName TogglePickAxeName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadResetCameraName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadTogglePickAxeHoldGyroName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadToggleCrouchHoldGyroName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadGyroModifierName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadResetCameraHoldGyroName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ToggleCreativePhoneName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName ToggleQuickMenuName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadSquadQuickChatPickerName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadEmotePickerOrReplayLastEmoteHoldName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadEmotePickerOrReplayLastEmoteHoldWhileBuildingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadEmotePickerOrReplayLastEmoteHoldWhileEditingName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadChatPickerName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName GamepadSwitchModeName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveToolEquippedGrabOrLetGoName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveToolEquippedCopyGrabOrDuplicateName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativePossessPropActivateName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveToolEquippedDeleteName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeToggleGhostName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeToggleInvulnerablityName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeSpawnModeratorBotName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeDespawnModeratorBotName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeModeratorOpenPhotoModeName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeToggleHeatmapName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveToolMultiSelectName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveToolClearMultiSelectName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyLetGoName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyDuplicateName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyDropToFloorName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyRotateClockwiseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyRotateCounterclockwiseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelySwitchAxisName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyPushName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyPullName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyExitName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveObjectsFreelyChangePrecisionLevelName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridLetGoName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridDuplicateName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridRotateClockwiseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridRotateCounterclockwiseName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridMirrorName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridExitName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeMoveBuildingsOnGridChangePrecisionLevelName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeFlyUpName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeFlyDownName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeIslandPanelSupportAffiliateName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeIslandPanelStartMinigameName;

	UPROPERTY(EditAnywhere, Category="Action Bindings")
	FName CreativeIslandPanelToggleDetailsName;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels", meta=(TitleProperty="NormalText"))
	TMap<FGameplayTag, FScreenLabelText> ScreenLabels;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText MoveLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText LookLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText SwitchQuickbarLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText JumpLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText SprintLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText AutoSprintLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText NextWeaponLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PreviousWeaponLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText NextWeaponTapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PreviousWeaponTapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText NextBuildingPieceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PreviousBuildingPieceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadStairSelectAndPlaceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadRoofSelectAndPlaceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadWallSelectAndPlaceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadFloorSelectAndPlaceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadTrapSelectAndPlaceLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadTrapPickerHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GamepadChangeMaterialOrTrapPickerLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText HarvestWeaponHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText HarvestWeaponLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText AimDownSightsLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText AimDownSightsHeavyMeleeLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText Ability1Label;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText Ability2Label;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText Ability3Label;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText Gadget1Label;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText Gadget2Label;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText RotateBuildingLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText RotateBuildingTapRepairHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText BuildingEditResetLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText ReloadLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText ReloadTapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText CraftAmmoHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText InteractTapHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText UseOrReloadLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText CrouchLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText ToggleFullScreenMapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText ToggleInventoryLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText GameMenuLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PlaceBuildingOrTrapConfirmLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText AttackConfirmLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText ChangeMaterialLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText EmoteLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText EmoteOrQuickChatOrSpotEnemyLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText ChatHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PickTrapTapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText TrapInventoryHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PickTrapTapHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText PickTrapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText EditBuildingPieceHoldLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText SwitchQuickBarTapLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText DeployHoverboardLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText RepairOrImproveLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText RepairLabel;

	UPROPERTY(EditAnywhere, Category="Controller Config Screen Labels")
	FText RepairHoldLabel;

	UPROPERTY()
	TArray<FFortActionKeyMapping> InputOptionsList;

};

