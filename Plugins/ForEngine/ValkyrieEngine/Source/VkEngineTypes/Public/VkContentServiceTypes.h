// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Misc/DateTime.h"
#include "VkContentServiceTypes.generated.h"

UENUM()
enum class EConsumerRole : uint8
{
	Server = 0,
	Client = 1,
	Editor = 2,
};

UENUM()
enum class EVkIdType : uint8
{
	Account = 0,
	Team = 1,
};

UENUM()
enum class EVkLinkPublishMode : uint8
{
	Live = 0,
	Playtest = 1,
};

UENUM()
enum class EVkModuleAccess : uint8
{
	Private = 0,
	// only available within the same project

	Protected = 1,
	// available to any project owned by the same team (at the time of dependency creation)

	Public = 2,
};

UENUM()
enum class EVkModuleModerationSource : uint8
{
	System = 0,
	Manual = 1,
	Error = 2,
};

UENUM()
enum class EVkModulePublishStatus : uint8
{
	Unreleased = 0,
	PublishedLive = 1,
};

UENUM()
enum class EVkModuleSafetyStatus : uint8
{
	Unknown = 0,
	Passed = 1,
	FailedSoft = 2,
	FailedHard = 3,
};

UENUM()
enum class EVkTicketStatus : int8
{
	None = 0,
	Succeeded = 1,
	Running = 2,
	Failed = 3,
};

USTRUCT()
struct FVkContentFilter
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Platform;

	UPROPERTY()
	FString BuildVersion;

};

USTRUCT()
struct FVkArtifactOption
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ArtifactId;

	UPROPERTY()
	EConsumerRole Role;

	UPROPERTY()
	FVkContentFilter Filter;

};

USTRUCT()
struct FVkBuildVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Major;

	UPROPERTY()
	int32 Minor;

	UPROPERTY()
	int32 Patch;

};

USTRUCT()
struct FVkInstallMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GameFeaturePluginUri;

};

USTRUCT()
struct FVkModuleBinaries
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BaseUrl;

	UPROPERTY()
	FString Manifest;

	UPROPERTY()
	TArray<FString> Files;

	UPROPERTY()
	double TotalSizeKb;

	UPROPERTY()
	double ManifestSizeKb;

	UPROPERTY()
	double ManifestDiskSizeKb;

	UPROPERTY()
	double ManifestDownloadSizeKb;

	UPROPERTY()
	TArray<FVkInstallMetadata> InstallMetadata;

};

USTRUCT()
struct FVkResolvedModule
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	int32 Version;

	UPROPERTY()
	FString ArtifactId;

	UPROPERTY()
	FString CookJobId;

	UPROPERTY()
	FVkModuleBinaries Binaries;

};

USTRUCT()
struct FVkContentManifest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FVkResolvedModule> Content;

};

USTRUCT()
struct FVkModuleVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	int32 Version;

};

USTRUCT()
struct FVkModuleVersionWithArtifacts : public FVkModuleVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FVkArtifactOption> Artifacts;

};

USTRUCT()
struct FVkModuleVersionRef
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	int32 Version;

};

USTRUCT()
struct FVkResolvedContent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkModuleVersionRef Root;

	UPROPERTY()
	TMap<FString, int32> Resolutions;

};

USTRUCT()
struct FVkContentPackage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	TMap<FString, FString> ProjectFlags;

	UPROPERTY()
	TArray<FVkModuleVersionWithArtifacts> Content;

	UPROPERTY()
	FVkResolvedContent Resolved;

};

USTRUCT()
struct FVkContentPackageRequest : public FVkResolvedContent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

};

USTRUCT()
struct FVkCookedContentPackage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	TMap<FString, FString> ProjectFlags;

	UPROPERTY()
	TArray<FVkResolvedModule> Content;

	UPROPERTY()
	FVkResolvedContent Resolved;

};

USTRUCT()
struct FVkCookedModuleUpdate : public FVkModuleVersion
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ArtifactId;

	UPROPERTY()
	FString CookJobId;

};

USTRUCT()
struct FVkCookedContentUpdate
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 PendingCookRequests;

	UPROPERTY()
	FVkResolvedContent Resolved;

	UPROPERTY()
	TArray<FVkCookedModuleUpdate> Content;

};

USTRUCT()
struct FVkCreateModuleRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleName;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	FString ContentType;

	UPROPERTY()
	TMap<EConsumerRole, bool> Relevance;

	UPROPERTY()
	FString DesiredModuleId;

};

USTRUCT()
struct FVkCreateModuleVersionRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FString> RawFiles;

	UPROPERTY()
	TArray<FVkModuleVersionRef> Dependencies;

	UPROPERTY()
	TArray<FString> StaticDependencies;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	FString Checksum;

	UPROPERTY()
	FString ManifestLink;

};

USTRUCT()
struct FVkCreateProjectRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString DesiredProjectId;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	FJsonObjectWrapper SysMeta;

};

USTRUCT()
struct FVkExtendedErrorParam
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Key;

	UPROPERTY()
	FString Value;

};

USTRUCT()
struct FVkExtendedError
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FormatKey;

	UPROPERTY()
	FString FormatNs;

	UPROPERTY()
	FString Message;

	UPROPERTY()
	TArray<FVkExtendedErrorParam> Params;

};

USTRUCT()
struct FVkExtendedErrorInformation
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ErrorCode;

	UPROPERTY()
	FString ErrorMessage;

	UPROPERTY()
	TArray<FVkExtendedError> AdditionalErrors;

};

USTRUCT()
struct FVkFileSize
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Types;

	UPROPERTY()
	int64 SourceSize;

	UPROPERTY()
	int64 UncompressedSize;

	UPROPERTY()
	int64 CompressedSize;

};

USTRUCT()
struct FVkFileSizes
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FVkFileSize> FileSizeMap;

};

USTRUCT()
struct FVkFoundMatchingArtifact
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ArtifactId;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	FVkContentFilter Filter;

};

USTRUCT()
struct FVkGenerateTestcodeRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkResolvedContent Content;

	UPROPERTY()
	FString CommitMessage;

	UPROPERTY()
	FJsonObjectWrapper MatchmakingConfig;

	UPROPERTY()
	FString SourceControlBase;

};

USTRUCT()
struct FVkJobOutput
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BaseUrl;

	UPROPERTY()
	double TotalSizeKb;

	UPROPERTY()
	double UserContentTotalSizeKb;

	UPROPERTY()
	TArray<FString> Files;

	UPROPERTY()
	FString Manifest;

};

USTRUCT()
struct FVkLaunchData_Link
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LinkCode;

	UPROPERTY()
	int32 Version;

};

USTRUCT()
struct FVkLinkCodeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LinkCode;

	UPROPERTY()
	int32 Version;

	UPROPERTY()
	FString Type;

	UPROPERTY()
	bool IsActive;

	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString CreatorName;

	UPROPERTY()
	FJsonObjectWrapper Metadata;

};

USTRUCT()
struct FVkLinkCodePublicModules
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LinkCode;

	UPROPERTY()
	int32 Version;

	UPROPERTY()
	FString Type;

	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	TMap<FString, int32> Public_Modules;

};

USTRUCT()
struct FVkTypedId
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	EVkIdType Type;

};

USTRUCT()
struct FVkModuleDoc
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	FDateTime Created;

	UPROPERTY()
	FDateTime Updated;

	UPROPERTY()
	FVkTypedId Author;

	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString ModuleName;

	UPROPERTY()
	FString ContentType;

	UPROPERTY()
	TMap<EConsumerRole, bool> Relevance;

	UPROPERTY()
	FString AliasForModuleId;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	int32 LatestVersion;

};

USTRUCT()
struct FVkModuleVersionDoc
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	int32 Version;

	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	EVkModuleAccess Access;

	UPROPERTY()
	FDateTime Created;

	UPROPERTY()
	FVkTypedId Author;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	TArray<FVkModuleVersionRef> Dependencies;

	UPROPERTY()
	FVkJobOutput StagedFiles;

	UPROPERTY()
	FVkBuildVersion SourceVersion;

	UPROPERTY()
	FString ContentType;

	UPROPERTY()
	TMap<EConsumerRole, bool> Relevance;

	UPROPERTY()
	FString ArtifactKey;

	UPROPERTY()
	FString Checksum;

	UPROPERTY()
	TArray<FVkArtifactOption> Artifacts;

};

USTRUCT()
struct FVkModuleVersionModerationStatus
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ModuleId;

	UPROPERTY()
	int32 Version;

	UPROPERTY()
	FString MoreInfoUrl;

	UPROPERTY()
	EVkModulePublishStatus PublishStatus;

	UPROPERTY()
	EVkModuleSafetyStatus SafetyStatus;

	UPROPERTY()
	EVkModuleModerationSource ModerationSource;

};

USTRUCT()
struct FVkNamedId
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Id;

};

USTRUCT()
struct FVkProfileBuildResult_Client
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	FString BuildId;

	UPROPERTY()
	FString Platform;

	UPROPERTY()
	TMap<FString, float> Stat;

};

USTRUCT()
struct FVkProfileBuildResult_Duration
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime Start;

	UPROPERTY()
	FDateTime End;

};

USTRUCT()
struct FVkProfileBuildResult_Server
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BuildId;

	UPROPERTY()
	FString Platform;

	UPROPERTY()
	TMap<FString, float> Stat;

};

USTRUCT()
struct FVkProfileBuildResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float Score;

	UPROPERTY()
	FString SessionId;

	UPROPERTY()
	FVkProfileBuildResult_Duration Duration;

	UPROPERTY()
	FVkProfileBuildResult_Server Server;

	UPROPERTY()
	TArray<FVkProfileBuildResult_Client> Clients;

};

USTRUCT()
struct FVkProjectAccessControl
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool Read;

	UPROPERTY()
	bool Edit;

	UPROPERTY()
	bool Operate;

	UPROPERTY()
	bool Publish;

	UPROPERTY()
	bool Admin;

};

USTRUCT()
struct FVkPublishedLink
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LinkCode;

	UPROPERTY()
	int32 LinkVersion;

	UPROPERTY()
	FDateTime LastPublished;

	UPROPERTY()
	FString Base;

	UPROPERTY()
	FString CommitMessage;

	UPROPERTY()
	FVkProfileBuildResult ProfileResult;

};

USTRUCT()
struct FVkProjectDoc
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FDateTime Created;

	UPROPERTY()
	FVkTypedId Author;

	UPROPERTY()
	FVkTypedId Owner;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	FJsonObjectWrapper SysMeta;

	UPROPERTY()
	FVkPublishedLink LiveLink;

};

USTRUCT()
struct FVkProjectInfoSlim
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkTypedId Owner;

	UPROPERTY()
	FString Title;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	FString RcsProvider;

	UPROPERTY()
	FJsonObjectWrapper SysMeta;

};

USTRUCT()
struct FVkProjectLimitsDoc
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int64 PublishingMemorySize;

	UPROPERTY()
	int64 PublishingDownloadSize;

	UPROPERTY()
	int64 ProjectUploadSize;

	UPROPERTY()
	int32 ModuleUploadConcurrencyLimit;

	UPROPERTY()
	int64 FileCount;

	UPROPERTY()
	int64 IndividualFileSizeKb;

};

USTRUCT()
struct FVkProjectOwnerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Owner;

	UPROPERTY()
	FString Brand;

};

USTRUCT()
struct FVkProjectPlaytestAccessRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Users;

	UPROPERTY()
	FString PlaytestGroupId;

};

USTRUCT()
struct FVkProjectPlaytestAccessResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkNamedId Owner;

	UPROPERTY()
	FString OwnerType;

	UPROPERTY()
	TMap<FString, FVkProjectAccessControl> Playtesters;

};

USTRUCT()
struct FVkProjectSearchResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FDateTime Created;

	UPROPERTY()
	FDateTime Accessed;

	UPROPERTY()
	FJsonObjectWrapper Meta;

	UPROPERTY()
	FJsonObjectWrapper SysMeta;

	UPROPERTY()
	FString LinkCode;

};

USTRUCT()
struct FVkProjectSearchResultSlim
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FDateTime Date;

	UPROPERTY()
	FVkProjectInfoSlim Info;

	UPROPERTY()
	bool is_starred;

	UPROPERTY()
	bool is_new;

};

USTRUCT()
struct FVkVersionedLinkCode
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Mnemonic;

	UPROPERTY()
	int32 Version;

};

USTRUCT()
struct FVkProjectSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString UniqueId;

	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	FDateTime CreatedAt;

	UPROPERTY()
	int32 DeltaFileIndex;

	UPROPERTY()
	FVkResolvedContent Content;

	UPROPERTY()
	TArray<FVkVersionedLinkCode> Palette;

	UPROPERTY()
	FString MapPath;

	UPROPERTY()
	FJsonObjectWrapper MatchmakingConfig;

};

USTRUCT()
struct FVkProjectUserInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	FString Title;

	UPROPERTY()
	bool HasStar;

	UPROPERTY()
	bool IsNew;

	UPROPERTY()
	TMap<FString, bool> Access;

	UPROPERTY()
	TArray<FString> Permissions;

};

USTRUCT()
struct FVkVersePath
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString VersePath;

	UPROPERTY()
	FString Url;

};

USTRUCT()
struct FVkVersePathTarget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FVkVersionedLinkCode LinkCode;

};

USTRUCT()
struct FVkResolvedVersePath : public FVkVersePath
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkVersePathTarget Target;

};

USTRUCT()
struct FVkSnapshotDeltaFiles
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString SnapshotId;

	UPROPERTY()
	TMap<FString, FString> DeltaFileLinks;

};

USTRUCT()
struct FVkSnapshotSaveRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVkResolvedContent Content;

	UPROPERTY()
	TArray<FVkVersionedLinkCode> Palette;

	UPROPERTY()
	FString MapPath;

	UPROPERTY()
	FJsonObjectWrapper MatchmakingConfig;

};

USTRUCT()
struct FVkTeamAccessControl
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool Admin;

	UPROPERTY()
	bool Edit;

	UPROPERTY()
	bool Operate;

	UPROPERTY()
	bool Publish;

};

USTRUCT()
struct FVkTeamAuthorizedEmailDomain
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Domain;

	UPROPERTY()
	FVkTeamAccessControl Access;

};

USTRUCT()
struct FVkTeamPublicProperties
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Description;

	UPROPERTY()
	TArray<FVkTeamAuthorizedEmailDomain> EmailDomains;

};

USTRUCT()
struct FVkTeamDoc
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TeamId;

	UPROPERTY()
	FDateTime Created;

	UPROPERTY()
	FDateTime Updated;

	UPROPERTY()
	FVkTypedId Owner;

	UPROPERTY()
	FVkTeamPublicProperties PublicProps;

	UPROPERTY()
	int32 MemberCount;

	UPROPERTY()
	FJsonObjectWrapper SysMeta;

};

USTRUCT()
struct FVkTeamMembershipResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	TMap<FString, bool> Access;

	UPROPERTY()
	FString Status;

	UPROPERTY()
	FString MembershipId;

	UPROPERTY()
	FString TeamId;

	UPROPERTY()
	FString AccountId;

	UPROPERTY()
	FDateTime Updated;

};

USTRUCT()
struct FVkTeamOwnerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Owner;

	UPROPERTY()
	FString Brand;

};

USTRUCT()
struct FVkTicketDetails
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EVkTicketStatus Status;

	UPROPERTY()
	FDateTime StartDate;

	UPROPERTY()
	FDateTime EndDate;

	UPROPERTY()
	FVkExtendedErrorInformation Error;

};

USTRUCT()
struct FVkTransferProjectRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString TeamId;

};

