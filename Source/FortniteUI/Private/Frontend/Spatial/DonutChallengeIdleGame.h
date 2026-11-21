// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "UIManager/FortActivatablePanel.h"
#include "DonutChallengeIdleGame.generated.h"

class UCommonButtonLegacy;
class UCurveFloat;
class UDonutChallengeIdleGame;
class UImage;
class UWidgetAnimation;

UENUM(BlueprintType)
enum EFortDonutIdleGameObject
{
	UnsetObject = 0,
	Tree = 1,
	Mound = 2,
	SmallMound = 3,
	JumpPad = 4,
	Torch = 5,
	PeelMonster = 6,
	Chimichanga = 7,
	Arm = 8,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDonutDayNightCycleChanged, bool, bIsDay);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDonutIdleGameEndScore, int32, NewEndScore, int32, NumAgroMonsters, int32, NumChimichangas);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDonutIdleGameScoreChanged, int32, NewScore);

UCLASS()
class UDonutChallengeIdleGame : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnDonutIdleGameScoreChanged OnNewHighScore;

	UPROPERTY(BlueprintAssignable)
	FOnDonutIdleGameScoreChanged OnDistanceScoreChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDonutIdleGameScoreChanged OnSpeedScoreChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDonutIdleGameScoreChanged OnStyleScoreChanged;

	UPROPERTY(BlueprintAssignable)
	FOnDonutIdleGameEndScore OnEndMatchScore;

	UPROPERTY(BlueprintAssignable)
	FOnDonutDayNightCycleChanged OnDayNightCycleChanged;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BPGameOver();

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnCollision(EFortDonutIdleGameObject ObjectType);

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnCrash();

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnFacingDirectionChanged(bool bIsLeftFacing);

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnFailedJumpPress();

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnGameInitialized();

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnJump();

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnMonsterNearChanged(bool bIsNearLevelMonster);

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnNextLevelReached();

	UFUNCTION(BlueprintImplementableEvent)
	void BPOnSpeedUpdated(int32 NewCurSpeed);

	UFUNCTION(BlueprintImplementableEvent)
	void BPShowHighScore(int32 inNewHighScore);

	UFUNCTION(BlueprintImplementableEvent)
	void BPUpdateDistance(int32 NewDistance);

	UFUNCTION(BlueprintImplementableEvent)
	void BPUpdateSpeed(int32 NewSpeed);

	UFUNCTION(BlueprintImplementableEvent)
	void BPUpdateStyle(int32 NewStyle);

	UFUNCTION(BlueprintImplementableEvent)
	void DebugBPFloat(float inFloat);

	UFUNCTION(BlueprintCallable)
	void StartGame();

private:
	UFUNCTION()
	void EndBumpyRide();

	UFUNCTION()
	void EndJump();

	UFUNCTION()
	void EndSuperJump();

	UFUNCTION()
	void TryJump();

	UPROPERTY(EditDefaultsOnly, Category="GameSettings")
	FLinearColor BoundsColor;

	UPROPERTY(EditDefaultsOnly, Category="GameSettings")
	float DayNightCycleTime;

	UPROPERTY(EditDefaultsOnly, Category="GameSettings")
	float PlayerTopSpeed;

	UPROPERTY(EditDefaultsOnly, Category="GameSettings")
	float BumpyRideSpeedReduction;

	UPROPERTY(EditDefaultsOnly, Category="GameSettings")
	FVector2D MapSize;

	UPROPERTY(Transient)
	FVector2D PlayerCollisionOffset;

	UPROPERTY(Transient)
	FVector2D PlayerCollisionSize;

	UPROPERTY(EditDefaultsOnly, Category="GameSettings")
	float MapScale;

	UPROPERTY(EditDefaultsOnly, Category="LevelGeneration")
	float MaxNumLevels;

	UPROPERTY(EditDefaultsOnly, Category="LevelGeneration")
	float ObjectSpawnPlacementRadius;

	UPROPERTY(EditDefaultsOnly, Category="LevelGeneration")
	int32 NumOfTreeSpawnAttempts;

	UPROPERTY(EditDefaultsOnly, Category="LevelGeneration")
	int32 NumOfRockSpawnAttempts;

	UPROPERTY(EditDefaultsOnly, Category="LevelGeneration")
	int32 NumOfBigRockSpawnAttempts;

	UPROPERTY(EditDefaultsOnly, Category="LevelGeneration")
	int32 NumOfJumpPadSpawnAttempts;

	UPROPERTY(EditDefaultsOnly, Category="LevelProgression")
	TObjectPtr<UCurveFloat> Curve_BonusSpawn_Trees;

	UPROPERTY(EditDefaultsOnly, Category="LevelProgression")
	TObjectPtr<UCurveFloat> Curve_BonusSpawn_SmallBumps;

	UPROPERTY(EditDefaultsOnly, Category="LevelProgression")
	TObjectPtr<UCurveFloat> Curve_BonusSpawn_Bumps;

	UPROPERTY(EditDefaultsOnly, Category="LevelProgression")
	TObjectPtr<UCurveFloat> Curve_BonusSpawn_JumpPads;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FName Param_Player_Direction;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FName Param_Player_FacingLeft;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush PlayerBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush TreeBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush RockBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush BigRockBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush JumpPadBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush TorchBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush MonsterBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush ChimiBrush;

	UPROPERTY(EditDefaultsOnly, Category="GameBrushes")
	FSlateBrush ArmBrush;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Jump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_MediumJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_SuperJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_BumpyRide;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Player;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_MobileInput;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_MobileInput_Background;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Jump;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutChallengeIdleGame", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MobileJump;

};

UCLASS(meta=(DisableNativeTick))
class UDonutIdleGameScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Transient, Category="DonutIdleGameScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> Anim_Intro;

	UPROPERTY(BlueprintReadOnly, Export, Category="DonutIdleGameScreen", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UDonutChallengeIdleGame> Widget_GameLayer;

};

